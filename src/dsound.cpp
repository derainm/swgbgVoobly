#include <Windows.h>
#include <stdio.h>
#include <direct.h>
#include <io.h>
typedef uintptr_t addr;
 
 
//files check for 1.0e
#include <sys/stat.h>
#include <string>
#include <fstream>
 
#include <TlHelp32.h>
#include "../build/drsLoader.h"
#include "../build/language.h"
#include "../build/wideScreen.h"
#include "../build/windowed.h"
//#include "../build/windowed.h"
//#include "../build/wideScreen.h"
//#include "../build/drs.h"
//#include "../build/drsLoader.h"

using namespace std;
 

struct dsound_dll
{
	HMODULE dll;
	FARPROC DirectSoundCreate;
	FARPROC DirectSoundEnumerateA;
	FARPROC DirectSoundEnumerateW;
	FARPROC DllCanUnloadNow;
	FARPROC DllGetClassObject;
	FARPROC DirectSoundCaptureCreate;
	FARPROC DirectSoundCaptureEnumerateA;
	FARPROC DirectSoundCaptureEnumerateW;
	FARPROC GetDeviceID;
	FARPROC DirectSoundFullDuplexCreate;
	FARPROC DirectSoundCreate8;
	FARPROC DirectSoundCaptureCreate8;
} dsound;

WRAPPER void _DirectSoundCreate() { VARJMP(dsound.DirectSoundCreate); }
WRAPPER void _DirectSoundEnumerateA() { VARJMP(dsound.DirectSoundEnumerateA); }
WRAPPER void _DirectSoundEnumerateW() { VARJMP(dsound.DirectSoundEnumerateW); }
WRAPPER void _DllCanUnloadNow() { VARJMP(dsound.DllCanUnloadNow); }
WRAPPER void _DllGetClassObject() { VARJMP(dsound.DllGetClassObject); }
WRAPPER void _DirectSoundCaptureCreate() { VARJMP(dsound.DirectSoundCaptureCreate); }
WRAPPER void _DirectSoundCaptureEnumerateA() { VARJMP(dsound.DirectSoundCaptureEnumerateA); }
WRAPPER void _DirectSoundCaptureEnumerateW() { VARJMP(dsound.DirectSoundCaptureEnumerateW); }
WRAPPER void _GetDeviceID() { VARJMP(dsound.GetDeviceID); }
WRAPPER void _DirectSoundFullDuplexCreate() { VARJMP(dsound.DirectSoundFullDuplexCreate); }
WRAPPER void _DirectSoundCreate8() { VARJMP(dsound.DirectSoundCreate8); }
WRAPPER void _DirectSoundCaptureCreate8() { VARJMP(dsound.DirectSoundCaptureCreate8); }

void init_dsound(HINSTANCE hInst)
{
	TCHAR dsound_dll_path[MAX_PATH];

	GetEnvironmentVariable("windir", dsound_dll_path, MAX_PATH);
	strcat_s(dsound_dll_path, "\\System32\\dsound.dll");

	dsound.dll = LoadLibrary(dsound_dll_path);

	dsound.DirectSoundCreate = GetProcAddress(dsound.dll, "DirectSoundCreate");
	dsound.DirectSoundEnumerateA = GetProcAddress(dsound.dll, "DirectSoundEnumerateA");
	dsound.DirectSoundEnumerateW = GetProcAddress(dsound.dll, "DirectSoundEnumerateW");
	dsound.DllCanUnloadNow = GetProcAddress(dsound.dll, "DllCanUnloadNow");
	dsound.DllGetClassObject = GetProcAddress(dsound.dll, "DllGetClassObject");
	dsound.DirectSoundCaptureCreate = GetProcAddress(dsound.dll, "DirectSoundCaptureCreate");
	dsound.DirectSoundCaptureEnumerateA = GetProcAddress(dsound.dll, "DirectSoundCaptureEnumerateA");
	dsound.DirectSoundCaptureEnumerateW = GetProcAddress(dsound.dll, "DirectSoundCaptureEnumerateW");
	dsound.GetDeviceID = GetProcAddress(dsound.dll, "GetDeviceID");
	dsound.DirectSoundFullDuplexCreate = GetProcAddress(dsound.dll, "DirectSoundFullDuplexCreate");
	dsound.DirectSoundCreate8 = GetProcAddress(dsound.dll, "DirectSoundCreate8");
	dsound.DirectSoundCaptureCreate8 = GetProcAddress(dsound.dll, "DirectSoundCaptureCreate8");
}

int AoK20ab, AoK20, AoC10Ce, AoC10, UserPatch;//(user patch version aofe + 1.5 +1.1 .. etc)

inline bool exists_File(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}
bool dataPatch = false;
bool expanding_fronts = false;

void* voob_log = 0;

int last_t = 0;
int last_x = 0;
int last_y = 0;
int last_obj = 0;

__declspec(naked) void onVooblyWidescreenBug1() //004A940B
{
    __asm
    {
        and eax, 3F00h
        cmp     eax, 500h
        push    004A9415h
        ret
    }
}

__declspec(naked) void onVooblyWidescreenBug2() //004BE13F
{
    __asm
    {
        and edx, 3F00h
        cmp     edx, 500h
        push    004BE14Bh
        ret
    }
}

__declspec(naked) void onVooblyCampaignBug() //005F674F
{
    __asm
    {
        fnstsw  ax
        test    ah, 1
        jz      short loc_5F675D
        push    500h
        mov     edx, 005F6762h
        jmp     edx
        loc_5F675D :
        mov     edx, 005F675Dh
            jmp     edx
    }
}

__declspec(naked) void onVooblyWidescreenBug3() //0046A91A
{
    __asm
    {
        jnz     short loc_46A959
        push    0
        add     edx, 39Eh
        push    0046A924h
        ret
        loc_46A959 :
        push    0046A959h
            ret
    }
}

__declspec(naked) void onVooblyWidescreenBug4() //004290A3
{
    __asm
    {
        mov     eax, [esi]
        push    ebx
        push    edi
        push    400h
        mov     edx, 004290ACh
        jmp     edx
    }
}

/*
__declspec(naked) void onVooblyWidescreenBug5() //00502881
{
    __asm
    {
        mov     eax, 004B7450h
        call    eax
        mov     eax, [esp + 1Ch]
        //
        mov     eax, 1280
        mov     ecx, [esp + 20h]
        mov     ecx, 1200
        cmp     eax, 1280
        jge     rec_ui_large
        cmp     eax, 1024
        jge     rec_ui_medium
        mov     edi, 4
        //lea     ebx, [ecx - 166]
        mov     ebx, 24Bh

rec_ui_finish:
        mov     eax, 00502887h
        mov     ecx, [esi + 1188h]
        jmp     eax

rec_ui_large:
        mov     edi, 18h
        //lea     ebx, [ecx - 324]
        mov     ebx, 320h
        jmp     rec_ui_finish

rec_ui_medium:
        mov     edi, 0Fh
        //lea     ebx, [ecx - 181]
        mov     ebx, 1B2h
        jmp     rec_ui_finish
    }
}
*/

__declspec(naked) void onVooblyFixTechTree()
{
    __asm
    {
        push    0FFFFFFFFh
        mov     eax, 005068C2h
        jmp     eax
    }
}

__declspec(naked) void onVooblyMirrorRandomTechTree() //0051834E
{
    __asm
    {
        cmp     eax, 1Eh
        jz      short fix_civ
        cmp     eax, 1Fh
        jz      short fix_civ
        mov     ecx, 0051835Ch
        jmp     ecx
        fix_civ :
        mov     eax, 1
            mov     ecx, 00518358h
            jmp     ecx
    }
}
//004B5F60 / $ 8B4424 10      MOV EAX, DWORD PTR SS : [ESP + 10]


void FixWidescreenVoonly()
{
    InjectHook((void*)0x004A940B, onVooblyWidescreenBug1,PATCH_JUMP);
    InjectHook((void*)0x004BE13F, onVooblyWidescreenBug2, PATCH_JUMP);
    //voobly campaign bug
    InjectHook((void*)0x005F674F, onVooblyCampaignBug, PATCH_JUMP);
    //voobly various widescreen bugs
    InjectHook((void*)0x0046A91A, onVooblyWidescreenBug3, PATCH_JUMP);
    InjectHook((void*)0x004290A3, onVooblyWidescreenBug4, PATCH_JUMP);
    //g_pVoobly->WriteJump(0x00502848, onVooblyWidescreenBug5);
    //voobly tech tree bug
    writeDword(0x004FA41C, (DWORD)onVooblyFixTechTree - 0x004FA420);
    writeDword(0x004FBB6F, (DWORD)onVooblyFixTechTree - 0x004FBB73);
}
void init()
{
	////00699D9C  69 6E 74 65 72 66 61 63 2E 64 72 73              interfac.drs
 //  //00699D9C  77 69 64 65 5F 70 31 2E 64 72 73 20              wide_p1.drs
	//BYTE  SWGBinterfacDrs[13]{ 0x77,0x69,0x64,0x65,0x5F,0x70,0x31,0x2E,0x64,0x72,0x73,0x00,0x00 };
	//writeData((DWORD)0x0699D9C, SWGBinterfacDrs, 13);
	//windowedHook();
	//LoadLibraryA("Voobly Mods\\SWBGCC\\Patches\\efPatch\\userpatch.dll");
//wideScreenHook();
//windowedHook();
//setDRSLoadHooks(1, true);
//no cd 
//Nop(0x050FCFD, 6);
	//////LoadLibrary("wndmode.dll");
	//////writeByte(0x0047166E, 0x90);
	//////writeByte(0x0047166F, 0x90);
	//////writeDword(0x00471670, 0x90909090);
	//////writeDword(0x00471674, 0x90909090);
	//////writeDword(0x00471678, 0x90909090);
	//////writeDword(0x0047167C, 0x90909090);
	//////writeByte(0x00471680, 0x90);
	//////writeByte(0x00471681, 0x90);
	//wideScreenHook();
    //FixWidescreenVoonly();
	//windowedHook();
setDRSLoadHooks();
languageOverwrite1();

//fix widescreen
////004F6709     EB 64          JMP SHORT battlegr.004F676F
//writeByte(0x04F6709, 0xEB);
//004F6757     C7 44 24 3C E8 C40000    MOV DWORD PTR SS:[ESP+3C],0C4E8
//writeByte(0x04F6757+4, 0xE8);
 
 

//LoadLibraryA("C:\\Users\\m\\Documents\\swgb\\Star Wars - Galactic Battlegrounds\\Game\\Voobly Mods\\SWBGCC\\Patches\\efpatch\\userpatch\\userpatch.dll");
}



BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID)
{
	//bool dsoundd = true;
	if (reason == DLL_PROCESS_ATTACH)
	{
		//load patch here + dsound library
		//if(dsoundd)
			//init_dsound(hInst);
		init();

	}

	if (reason == DLL_PROCESS_DETACH)
	{
		//if(dsoundd)
			//FreeLibrary(dsound.dll);
	}

	return TRUE;
}
