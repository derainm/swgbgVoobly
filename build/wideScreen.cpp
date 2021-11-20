#include "wideScreen.h"
//#include "drsfile.h"

#include <atomic>
#include <stdio.h>
#include <string>
#include "MemoryMgr.h"
//#include "slp.h"
 
//#include "slp.h"



void __declspec(naked) Aoc10CWidescreenResizeScreenUserPatch()
{
	__asm
	{
	}
}
 

#define RESOLUTION_TOOL_VERSION 100005

 
bool patchEXE(int X, int Y) //needs to be completed...
{
 
    if (Y >= 1024)
    {
        writeDwordF3(0x24B66, Y); //ok
        writeDwordF3(0x24BB3, X); //ok
        writeDwordF3(0x261FD, Y); //ok
        writeDwordF3(0x2623A, X); //ok
        writeDwordF3(0x2680C, Y); //ok
        writeDwordF3(0x26845, X); //ok
        //writeDwordF3(0x290A8, Y); //probably not, try removing !!!
        writeDwordF3(0x2AA3E, X); //ok
        writeDwordF3(0x2AA52, X - 340); //could be
        writeDwordF3(0x5A365, X); //ok
        writeDwordF3(0x5A3CE, X); //ok
        writeDwordF3(0x5ACBA, X); //ok
        writeDwordF3(0x5ACBF, Y); //ok
        writeDwordF3(0x5ACFB, X + 1); //ok
        writeDwordF3(0x639FB, Y); //ok
        writeDwordF3(0x63B9E, Y + 1); //mm ok
        writeDwordF3(0x63E9F, Y); //ok
        //float hMul = (float)Y / 600;
        //hMul = 0;
        //writeDword (0x00463EAB, *(int*)&hMul);
        writeDwordF3(0x6A916, X); //ok
        //writeDwordF3(0x6A920, Y - 98); // TECH TREE ~!!                     voobly
        writeDwordF3(0x70D36, X); //ok
        writeDwordF3(0x70DFB, X); //ok
        writeDwordF3(0x70E04, Y); //ok
        writeDwordF3(0x70E16, X + 1); //ok
        writeDwordF3(0x70E1F, Y + 1); //ok
        writeDwordF3(0x710D4, X); //ok
        writeDwordF3(0x710DB, X + 1); //check these 4, probably fine
        writeDwordF3(0x7114B, X + 1);
        writeDwordF3(0x711CD, X + 1);
        writeDwordF3(0x71247, X + 1);
        //writeDwordF3(0xA9411, X); //almost definitely wrong !!!             voobly
        writeDwordF3(0xB7E39, X); //might be ok
        //writeDwordF3(0xBE147, X); //almost definitely wrong !!!             voobly
        writeDwordF3(0xF670C, X); //ok
        writeDwordF3(0xFDAF2, X + 1); //mm ok
        writeDwordF3(0xFDAFB, Y + 1); //mm ok
        writeDwordF3(0xFDB20, X); //ok
        writeDwordF3(0xFDB29, Y); //ok
        writeDwordF3(0x1003A8, X); //ok
        writeDwordF3(0x1003D5, X); //ok
        writeDwordF3(0x1003E3, X - 298); //some item icon, check
        writeDwordF3(0x1003E8, Y - 340);
        //writeDwordF3(0x1003E3, Y-42); //some item icon, old ver
        //writeDwordF3(0x1003E8, X-340);
        writeDwordF3(0x102852, X); //rec game UI
        writeDwordF3(0x10285E, Y - 224); //rec game UI
        writeDwordF3(0x10C987, X); //ok
        writeDwordF3(0x10E4CD, X); //ok
        writeDwordF3(0x10E4D2, Y); //ok
        writeDwordF3(0x10EDCC, X); //weird, likely OK
        writeDwordF3(0x1D853F, X); //most likely
        writeDwordF3(0x1D98E9, X); //likely OK
        //writeDwordF3(0x1F6757, X); //not resolution                            voobly
    }
    else if (Y >= 768)
    {
        writeDwordF3(0x24B66, X); //ok
        writeDwordF3(0x24BAC, Y); //ok
        writeDwordF3(0x24BB3, X + 1); //ok
        writeDwordF3(0x261FD, X); //ok
        writeDwordF3(0x26217, Y); //ok
        //writeDwordF33(0x2623A, X + 1); //not needed?
        writeDwordF3(0x2680C, X); //ok
        writeDwordF3(0x2683B, Y); //ok
        writeDwordF3(0x26845, X + 1); //not needed?
        //writeDwordF3 (0x290A8, X); //test. not res?                           voobly
        writeDwordF3(0x2AA37, X); //ok
        writeDwordF3(0x2AA3E, X + 1); //not needed?
        writeDwordF3(0x2AA59, X - 274); //-> should be ok
        writeDwordF3(0x5A35E, X); //ok
        writeDwordF3(0x5A365, X + 1); //not needed?
        writeDwordF3(0x5A3AA, X); //ok
        writeDwordF3(0x5A3CE, X + 1); //not needed?
        writeDwordF3(0x5AC9F, X); //ok
        writeDwordF3(0x5ACA4, Y); //ok
        writeDwordF3(0x5ACBA, X + 1); //not needed?
        writeDwordF3(0x5ACBF, Y + 1);
        writeDwordF3(0x5ACFB, X + 2); //?
        writeDwordF3(0x63923, Y); //ok
        writeDwordF3(0x639FB, Y + 1); //block higher res
        writeDwordF3(0x63B9E, Y + 2); //block higher res
        writeDwordF3(0x63E85, Y); //ok
        writeDwordF3(0x63E9F, Y + 1); //block higher res
        writeDwordF3(0x6A90E, X); //ok
        writeDwordF3(0x6A916, X + 1); //block higher res
        //writeDwordF3(0x6A930, Y - 103); // TECH TREE ~!!
        writeDwordF3(0x70D2B, X); //ok
        writeDwordF3(0x70D36, X + 1); //block higher res
        writeDwordF3(0x70DE0, X); //ok
        writeDwordF3(0x70DE9, Y); //ok
        writeDwordF3(0x70DFB, X + 1); //block higher res
        writeDwordF3(0x70E04, Y + 1); //--
        writeDwordF3(0x70E16, X + 2); //--
        writeDwordF3(0x70E1F, Y + 2); //--
        writeDwordF3(0x70EB5, X); //ok
        writeDwordF3(0x70EBE, Y); //ok
        writeDwordF3(0x70F5D, X); //ok
        writeDwordF3(0x70F66, Y); //ok
        writeDwordF3(0x7100B, X); //ok
        writeDwordF3(0x71014, Y); //ok
        writeDwordF3(0x7107E, X); //ok
        writeDwordF3(0x710D4, X + 1); //block higher res
        writeDwordF3(0x710DB, X + 2); //block higher res
        writeDwordF3(0x71144, X); //ok?
        writeDwordF3(0x7114B, X + 2); //block higher res
        writeDwordF3(0x711C6, X); //ok?
        writeDwordF3(0x711CD, X + 2); //block higher res
        writeDwordF3(0x71240, X); //ok?
        writeDwordF3(0x71247, X + 2); //block higher res
        //writeDwordF3(0xA9411, X+1); //not res
        writeDwordF3(0xB7E14, X); //ok
        writeDwordF3(0xB7E39, X + 1); //ok
        //writeDwordF3(0xBE147, X+1); //not res
        writeDwordF3(0xF6705, X); //ok
        writeDwordF3(0xF670C, X + 1); //block higher res
        writeDwordF3(0xFDAF2, X + 2); //not needed?
        writeDwordF3(0xFDAFB, Y + 2);
        writeDwordF3(0xFDB20, X + 1);
        writeDwordF3(0xFDB29, Y + 1);
        writeDwordF3(0xFDB6C, X); //ok
        writeDwordF3(0xFDB75, Y); //ok
        //writeDwordF3(0x1003A8, X+1); //test!!!         (!!!)
        writeDwordF3(0x1003D5, X + 1); //ok
        writeDwordF3(0x1003FD, X); //ok
        //writeDwordF3(0x1003E3:    D6    57
        //writeDwordF3(0x1003E8:    AC    0D
        writeDwordF3(0x1003FD, X); //ok
        writeDwordF3(0x10040B, Y - 35); //ok, but test
        //writeDwordF3(0x100410, X  //same as above
        writeDwordF3(0x102852, X + 1); //ok
        writeDwordF3(0x102865, X); //rec game UI
        writeDwordF3(0x102871, Y - 181); //rec game UI
        writeDwordF3(0x10C94A, X); //should be ok
        writeDwordF3(0x10C987, X + 1); //block higher res
        writeDwordF3(0x10E4B2, X); //ok
        writeDwordF3(0x10E4B7, Y); //ok
        writeDwordF3(0x10E4CD, X + 1); //block higher res
        writeDwordF3(0x10E4D2, Y + 1); //block higher res
        writeDwordF3(0x10EDC5, X); //ok
        writeDwordF3(0x10EDCC, X + 1); //ok
        writeDwordF3(0x1D8529, X); //ok
        writeDwordF3(0x1D853F, X + 1); //ok
        writeDwordF3(0x1D98DA, X);
        writeDwordF3(0x1D98E9, X + 1);
        //writeDwordF3(0x1F6757, X+1); //not res
    }
    //else
    //{
    //    MessageBox(0, "Resolutions lower than 768V are not supported", "Error", MB_ICONERROR);
    //}

    if (Y >= 1024)
    {
        writeByte(0x0042622F, 0x90);   //force 1280 screen setting
        writeByte(0x00426230, 0x90);
        writeByte(0x00477509, 0xEB);
    }
    else
    {
        writeByte(0x00426203, 0x90);   //force 1024 screen setting
        writeByte(0x00426204, 0x90);
        writeByte(0x004774F5, 0xEB);
    }
    return true;
}

int findRectOffset(void* drsRects, const char* itemname)
{
    int i = 0;
    while (memcmp(itemname, (char*)drsRects + i, strlen(itemname)) != 0)
        i++;
    return i;
}

//void patchRect(int x,
//    int y,
//    const char* itemName, //name of the control, open 53290 in interfac.drs for details
//    bool addX, //control needs to be moved horizontally
//    bool addY, //control needs to be moved vertically
//    bool addW, //control needs to be stretched horisontally
//    bool addH, //control needs to be stretched vertically
//    int* size, //returns the new size of the DRS item
//    void* drsRects)
//{
//    log("Resolution: patching rect \"%s\", params: %d, %d, %d, %d",
//        itemName, addX, addY, addW, addH);
//
//    char* endbuf = (char*)malloc(4096);
//
//    int X800; //see 53290 in interfac.drs to understand how this works
//    int Y800;
//    int W800;
//    int H800;
//    int X1024;
//    int Y1024;
//    int W1024;
//    int H1024;
//    int X1280;
//    int Y1280;
//    int W1280;
//    int H1280;
//    char scanArg[128];
//    char oldRects[128];
//    char newRects[128];
//    sprintf(scanArg, "%s\t%%d\t%%d\t%%d\t%%d\t%%d\t%%d\t%%d\t%%d\t%%d\t%%d\t%%d\t%%d\t%%s", itemName);
//    sscanf((char*)drsRects + findRectOffset(drsRects, itemName), scanArg,
//        &X800, &Y800, &W800, &H800,
//        &X1024, &Y1024, &W1024, &H1024,
//        &X1280, &Y1280, &W1280, &H1280,
//        endbuf);
//    sprintf(oldRects, "\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t", //tab value tab value...
//        X800, Y800, W800, H800,
//        X1024, Y1024, W1024, H1024,
//        X1280, Y1280, W1280, H1280);
//    if (addX)
//        if (y >= 1024)
//            X1280 += x - 1280;
//        else if (y >= 768)
//            X1024 += x - 1024;
//        else
//            exit(1);
//    if (addY)
//        if (y >= 1024)
//            Y1280 += y - 1024;
//        else if (y >= 768)
//            Y1024 += y - 768;
//        else
//            exit(1);
//    if (addW)
//        if (y >= 1024)
//            W1280 += x - 1280;
//        else if (y >= 768)
//            W1024 += x - 1024;
//        else
//            exit(1);
//    if (addH)
//        if (y >= 1024)
//            H1280 += y - 1024;
//        else if (y >= 768)
//            H1024 += y - 768;
//        else
//            exit(1);
//    sprintf(newRects, "\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t",
//        X800, Y800, W800, H800,
//        X1024, Y1024, W1024, H1024,
//        X1280, Y1280, W1280, H1280);
//
//    int dst;
//    int src;
//    int n;
//
//    if (strlen(oldRects) != strlen(newRects)) //adjust data...
//    {
//        dst = (int)drsRects + findRectOffset(drsRects, itemName) + strlen(itemName) + strlen(newRects) - strlen(oldRects);
//        src = (int)drsRects + findRectOffset(drsRects, itemName) + strlen(itemName);
//        n = *size - findRectOffset(drsRects, itemName) + strlen(itemName);
//        memmove((void*)dst, (void*)src, n);
//        *size += strlen(newRects) - strlen(oldRects);
//        memcpy((void*)src, newRects, strlen(newRects));
//    }
//    else //don't adjust data...
//    {
//        dst = (int)drsRects + findRectOffset(drsRects, itemName) + strlen(itemName);
//        memcpy((void*)dst, newRects, strlen(newRects));
//    }
//
//    free(endbuf);
//
//    log("Resolution: rect patching done");
//}

//void patchResRects(int x, int y)//, DRS* drs)
//{
//    int size;
//
//    //DRS x1;
//    if (!x1.loadDRS("data\\interfac_x1.drs"))
//    {
//        char err[0x100];
//        sprintf(err, "Cannot load interfac_x1.drs");
//        log(err);
//        MessageBox(NULL, err, "Error", MB_ICONERROR);
//        exit(0);
//    }
//    //void* drsRects2 = x1.getFile(53290, &size);
//    //if (!drsRects2)
//    //{
//    //    char err[0x100];
//    //    sprintf(err, "Cannot load BIN 53290 from interfac_x1.drs");
//    //    log(err);
//    //    MessageBox(NULL, err, "Error", MB_ICONERROR);
//    //    exit(0);
//    //}
//    void* drsRects = malloc(size * 2);
//    memcpy(drsRects, drsRects2, size);
//    free(drsRects2);
//    //2E5D7BFC  49 74 65 6D 20 4E 61 6D  Item NamResolution Specific Rects
//
//
//    patchRect(x, y, "ToolBox", 0, 0, 1, 0, &size, drsRects);
//    patchRect(x, y, "Main Viewport with toolbox", 0, 0, 1, 1, &size, drsRects);
//    patchRect(x, y, "Main Viewport w/o toolbox", 0, 0, 1, 1, &size, drsRects);
//    patchRect(x, y, "Inventory Panel", 1, 1, 0, 0, &size, drsRects);
//    patchRect(x, y, "Map View", 1, 1, 0, 0, &size, drsRects);
//    patchRect(x, y, "Age Panel", 0, 1, 1, 0, &size, drsRects);
//    patchRect(x, y, "Objectives Changed Text", 1, 0, 0, 0, &size, drsRects);
//    patchRect(x, y, "FPS Panel", 1, 1, 0, 0, &size, drsRects);
//    patchRect(x, y, "Object Panel", 0, 1, 1, 0, &size, drsRects);
//    patchRect(x, y, "Action Buttons", 0, 1, 0, 0, &size, drsRects);
//    patchRect(x, y, "Objectives Button", 1, 1, 0, 0, &size, drsRects);
//    patchRect(x, y, "Tech Tree Button", 1, 1, 0, 0, &size, drsRects);
//    patchRect(x, y, "Chat Button", 1, 1, 0, 0, &size, drsRects);
//    patchRect(x, y, "Diplomacy Button", 1, 1, 0, 0, &size, drsRects);
//    patchRect(x, y, "Menu Button", 1, 1, 0, 0, &size, drsRects);
//    patchRect(x, y, "Flare Button", 1, 1, 0, 0, &size, drsRects);
//    patchRect(x, y, "Idle Villager Button", 1, 1, 0, 0, &size, drsRects);
//    patchRect(x, y, "Score Button", 1, 1, 0, 0, &size, drsRects);
//    patchRect(x, y, "Popup Help Button", 1, 1, 0, 0, &size, drsRects);
//    patchRect(x, y, "Advanced Button", 1, 1, 0, 0, &size, drsRects);
//    patchRect(x, y, "Normal Map Button", 1, 1, 0, 0, &size, drsRects);
//    patchRect(x, y, "Combat Map Button", 1, 1, 0, 0, &size, drsRects);
//    patchRect(x, y, "Resource Map Button", 1, 1, 0, 0, &size, drsRects);
//    patchRect(x, y, "Toggle MiniMap Terrain", 1, 1, 0, 0, &size, drsRects);
//
//    //drs->addFile(drsRects, size, 53290, DRS_BIN); //"bina"
//
//    free(drsRects);
//}
 


WORD Aoc10C_7A5608;
WORD Aoc10C_7A5609;
DWORD Aoc10C_0061442B = 0x061442B;
DWORD Aoc10C_005472B0 = 0x05472B0;
DWORD Aoc10C_00546250 = 0x0546250;
DWORD Aoc10C_005473A0 = 0x05473A0;
char res[] = "%d x %d";
//006330C4  /$ 55             PUSH EBP
DWORD battlegr_0061442B = 0x06330C4;
//004D37C0  /$ 66:8B4424 04   MOV AX,WORD PTR SS:[ESP+4]
DWORD battlegr_004D37C0 = 0x04D37C0;
//004D2620  /$ 8B4424 04      MOV EAX,DWORD PTR SS:[ESP+4]
DWORD battlegr_004D2620 = 0x04D2620;
//004598B1  |. E8 0E981D00    |CALL battlegr.006330C4
//004598C7  |. E8 E49F0700    |CALL battlegr.004D38B0
DWORD battlegr_004D38B0 = 0x04D38B0;

void  __declspec(naked) f_Aoc10C_007BF9D0()
{
    __asm
    {
        PUSH ESI
        PUSH EDI
        PUSH EBX
        MOV EAX, DWORD PTR DS : [Aoc10C_7A5608]
        MOV ECX, DWORD PTR SS : [ESP + 10h]
        CMP AL, BYTE PTR DS : [ECX + 54h]
        JNZ _007BFA69
        MOV ESI, DWORD PTR DS : [ECX + 0Ch]
        CMP ESI, 320h
        JL short _007BFA69
        MOV EDI, DWORD PTR DS : [ECX + 8h]
        CMP EDI, 258h
        JL short _007BFA69
        MOV EBX, DWORD PTR SS : [ESP + 14h]
        SUB ESP, 20h
        LEA ECX, DWORD PTR SS : [ESP]
        PUSH EDI
        PUSH ESI
        PUSH offset res; ASCII "%d x %d"//age2_x1_.007BFA70; ASCII "%d x %d"
        PUSH ECX
        CALL battlegr_0061442B//Aoc10C_0061442B
        ADD ESP, 10h
        LEA EDX, DWORD PTR SS : [ESP]
        MOV ECX, EBX
        XOR EAX, EAX
        PUSH EAX
        PUSH EDI
        MOV WORD PTR SS : [ESP + 2h] , SI
        PUSH EDX
        CALL battlegr_004D38B0//Aoc10C_005473A0
        ADD ESP, 20h
        MOV BYTE PTR DS : [Aoc10C_7A5609] , 1h
        //MOV ECX, DWORD PTR DS : [7912A0h]
        MOV ECX, DWORD PTR DS : [6A3684h]
        //MOV ECX, DWORD PTR DS : [ECX + 28h]
        MOV ECX, DWORD PTR DS : [ECX + 24h]
        //CMP DWORD PTR DS : [ECX + 8F4h] , ESI
        //JNZ short _007BFA69
        //CMP DWORD PTR DS : [ECX + 8FCh] , EDI
        //JNZ short _007BFA69
        MOV ECX, EBX
        MOVSX EAX, WORD PTR DS : [ECX + 0FCh]
        DEC EAX
        PUSH EAX
        CALL battlegr_004D37C0//Aoc10C_005472B0
        MOV ECX, EBX
        PUSH 1h
        PUSH 0h
        PUSH 7h
        CALL battlegr_004D2620//Aoc10C_00546250
        _007BFA69 :
        POP EBX
        POP EDI
        POP ESI
        RETN 8h


    }
}

DWORD Aoc10C_00547A00 = 0x0547A00;

DWORD battlegr_007BF9D0 = (DWORD)f_Aoc10C_007BF9D0;

//0045978C  |. E8 9FA70700    CALL battlegr.004D3F30
DWORD battlegr_004D3F30 = 0x04D3F30;

void __declspec(naked)  f_Aoc10C_007BF980()
{
    __asm
    {
        MOV ECX, DWORD PTR SS : [ESP + 4h]
        XOR EAX, EAX
        MOV WORD PTR DS : [Aoc10C_7A5608] , 20h//MOV WORD PTR DS : [7A5608h] , 20h
        MOV DWORD PTR DS : [ECX + 17Ch] , EAX
        CALL battlegr_004D3F30 //Aoc10C_00547A00
        _007BF99A :
        //MOV ECX, DWORD PTR DS : [7912A0h]
        MOV ECX, DWORD PTR DS : [6A3684h]
        //MOV EDX, DWORD PTR DS : [ECX + 6Ch]
        MOV EDX, DWORD PTR DS : [ECX + 68h]
        MOV ECX, DWORD PTR SS : [ESP + 4h]
        MOV EAX, DWORD PTR DS : [EDX + 18h]
        PUSH battlegr_007BF9D0//007BF9D0h
        PUSH ECX
        PUSH 0h
        MOV ECX, DWORD PTR DS : [EAX]
        PUSH 0h
        PUSH EAX
        CALL DWORD PTR DS : [ECX + 20h]
        CMP WORD PTR DS : [Aoc10C_7A5608] , 20h //WORD PTR DS : [7A5608h] , 20h
        MOV BYTE PTR DS : [Aoc10C_7A5608] , 8h//MOV BYTE PTR DS : [7A5608h] , 8h
        JE short _007BF99A
        RETN 4h
    }
}

DWORD Aoc10C_005BBCFA = 0x05BBCFA;
DWORD Aoc10C_005BBA15 = 0x05BBA15;
DWORD Aoc10C_0055EDA0 = 0x055EDA0;
DWORD Aoc10C_0055E9E0 = 0x055E9E0;

//004BA747  64                                               d


//0045A33C  |. E8 1FA90600    |CALL battlegr.004C4C60
//004BA740  /$ 6A FF          PUSH -1
DWORD battlegr_004BA740 = 0x04BA740;
//004BAB00  /$ 56             PUSH ESI
DWORD battlegr_004BAB00 = 0x04BAB00;
//0045A3EA  |> 6A 00          PUSH 0                                   ; /Arg8 = 00000000
DWORD battlegr_0045A3EA = 0x045A3EA;
//0045A6CF  |> 8B4C24 3C      MOV ECX,DWORD PTR SS:[ESP+3C]
DWORD battlegr_0045A6CF = 0x045A6CF;

DWORD battlegr_007BF980 = (DWORD)f_Aoc10C_007BF980;
void  __declspec(naked) addWidescreenControl1()
{
    __asm
    {
        MOV EBP, DWORD PTR SS : [ESP + 4Ch]
        XOR EDI, EDI
        PUSH 0Ah
        PUSH 73h
        PUSH 80h
        PUSH 0F7h
        PUSH 4Bh
        LEA EDI, DWORD PTR DS : [ESI + 888h]
        PUSH EDI
        PUSH ESI
        MOV ECX, ESI
        CALL battlegr_004BA740
        TEST EAX, EAX
        JE __005BBCFA
        MOV ECX, DWORD PTR DS : [EDI]
        PUSH 14h
        LEA EAX, DWORD PTR DS : [ESI + 88Ch]
        PUSH ECX
        PUSH EAX
        MOV ECX, ESI
        CALL battlegr_004BAB00
        TEST EAX, EAX
        JE __005BBCFA
        MOV ECX, DWORD PTR DS : [ESI + 888h]
        PUSH ECX
        CALL battlegr_007BF980//age2_x1.007BF980
        JMP battlegr_0045A3EA

        __005BBCFA :
        JMP battlegr_0045A6CF



    }
}
DWORD Aoc10C_005479C0 = 0x05479C0;
DWORD Aoc10C_005BC2EE = 0x05BC2EE;
//004D3ED0  /$ 8B81 F8000000  MOV EAX,DWORD PTR DS:[ECX+F8]
DWORD battlegr_004D3ED0 = 0x04D3ED0;
//0045ACCF   > 6A 00          PUSH 0
DWORD battlegr_0045ACCF = 0x045ACCF;



void __declspec(naked) addWidescreenControl2()
{
    __asm
    {
        MOV ECX, DWORD PTR DS : [ESI + 888h]
        CALL battlegr_004D3ED0//Aoc10C_005479C0
        MOV EDI, EAX
        XOR EBP, EBP
        MOV BP, AX
        SHR EDI, 10h
        JMP battlegr_0045ACCF//Aoc10C_005BC2EE
    }
}



//DWORD Aoc10C_00632C48 = 0x0632C48;
//00651C48   . 8B45 1C        MOV EAX,DWORD PTR SS:[EBP+1C]
DWORD battlegr_00632C48 = 0x0651C48;
void __declspec(naked) f_Aoc10C_007C1EF0()
{
    __asm
    {
        PUSH EBP
        MOV EBP, ESP
        PUSH EBX
        PUSH ESI
        PUSH EDI
        XOR EDX, EDX
        MOV ECX, DWORD PTR SS : [EBP + 0Ch]
        MOV EAX, DWORD PTR SS : [EBP + 14h]
        MOV DWORD PTR DS : [7A4024h] , ECX
        LEA ECX, DWORD PTR DS : [EAX + ECX - 1h]
        MOV DWORD PTR DS : [7A4028h] , ECX
        JMP battlegr_00632C48
    }
}
DWORD Aoc10C_7A5500;
void __declspec(naked) f_Aoc10C_007C1F20()
{
    __asm
    {
        PUSH EBP
        MOV EBP, ESP
        PUSH EBX
        PUSH ESI
        PUSH EDI
        MOV EBX, DWORD PTR DS : [Aoc10C_7A5500]
        XOR EDX, EDX
        AND EBX, EBX
        JE short _007C1F4A
        MOV DWORD PTR DS : [7A4004h] , EBX
        MOV DWORD PTR DS : [7A4008h] , EBX
        MOV ECX, DWORD PTR SS : [EBP + 30h]
        MOV EAX, DWORD PTR SS : [EBP + 34h]
        MOV DWORD PTR DS : [EBX + 8h] , ECX
        MOV DWORD PTR DS : [EBX + 0Ch] , EAX
        _007C1F4A :
        MOV ECX, DWORD PTR SS : [EBP + 0Ch]
        MOV EAX, DWORD PTR SS : [EBP + 14h]
        MOV DWORD PTR DS : [7A4024h] , ECX
        LEA ECX, DWORD PTR DS : [EAX + ECX - 1h]
        MOV DWORD PTR DS : [7A4028h] , ECX
        JMP battlegr_00632C48
    }
}
DWORD Aoc10C_007C1EF0 = (DWORD)f_Aoc10C_007C1EF0;// 0x07C1EF0;
DWORD Aoc10C_007C1F20 = (DWORD)f_Aoc10C_007C1F20;// 007C1F20;
DWORD Aoc10C_006139B4 = 0x06139B4;
DWORD Aoc10C_006137C9 = 0x06137C9;
//00632CCA  /$ 55             PUSH EBP
DWORD battlegr_00632CCA = 0x0632CCA;
//00632D33  /$ 55             PUSH EBP
DWORD battlegr_00632D33= 0x0632D33;
//care in aoc we don't have same dimension, slp that explain bugs
void __declspec(naked) f_Aoc10C_007C1C38()
{
    __asm
    {
        MOV ESI, EDI
        MOV ECX, DWORD PTR SS : [EBP + 24h]
        MOV EAX, DWORD PTR SS : [EBP + 20h]
        MOV EDX, DWORD PTR SS : [EBP + 30h]
        PUSH 0h
        PUSH ECX
        PUSH EAX//y?
        PUSH 19h//top bare size
 
        PUSH EDX
        PUSH 0h
        PUSH ESI
        PUSH EBP
        CMP EDX, 400h//1024
        JGE short _007C1C60
        MOV DWORD PTR SS : [ESP + 20h] , 0D6h
        JMP short _007C1C68
        _007C1C60 :
        MOV DWORD PTR SS : [ESP + 20h] , 116h
        _007C1C68 :
        SUB ESI, EDX
        AND ESI, ESI
        JL _007C1EE3
            _007C1C72 :
        //we remove top bar copy byte
        MOV DWORD PTR SS : [ESP + 4h] , ESI
        CALL Aoc10C_007C1EF0
        MOV DWORD PTR DS : [7A4038h] , 0h
        MOV EDX, DWORD PTR SS : [EBP + 30h]
        SUB ESI, EDX
        ADD ESI, 190h//fix top bare villager
        AND ESI, ESI
        JG short _007C1C72
        //we remove top bar copy byte
        MOV DWORD PTR SS : [ESP + 4h] , 0h
        CALL Aoc10C_007C1EF0
        MOV ECX, DWORD PTR DS : [7A4004h]
        MOV EAX, DWORD PTR SS : [EBP + 30h]
        MOV EDX, DWORD PTR SS : [EBP + 34h]
        MOV DWORD PTR SS : [ESP + 38h] , ECX
        MOV DWORD PTR SS : [ESP + 3Ch] , EAX
        MOV DWORD PTR SS : [ESP + 40h] , EDX
        MOV DWORD PTR SS : [ESP + 44h] , EDI
        MOV DWORD PTR SS : [ESP + 48h] , EBX
        MOV ESI, EBX
        MOV EAX, DWORD PTR DS : [Aoc10C_7A5500]
        TEST EAX, EAX
        JE short _007C1CDA
        CMP DWORD PTR DS : [EAX + 10h] , ESI
        JGE short _007C1D0D
        PUSH EAX
        CALL battlegr_00632CCA//Aoc10C_006139B4 heap free
        ADD ESP, 4h
        _007C1CDA :
        SHL ESI, 2h
        ADD ESI, 14h
        PUSH ESI
        PUSH 1h
        CALL battlegr_00632D33//Aoc10C_006137C9//heap alloc
        ADD ESP, 8h
        MOV DWORD PTR DS : [Aoc10C_7A5500] , EAX
        TEST EAX, EAX
        JE _007C1EE3
        LEA ECX, DWORD PTR DS : [ESI - 14h]
        LEA EDI, DWORD PTR DS : [EAX + 14h]
        MOV EDX, ECX
        SHR ECX, 2h
        REP STOS DWORD PTR ES : [EDI]
        MOV EDI, DWORD PTR SS : [ESP + 44h]
        MOV DWORD PTR DS : [EAX + 10h] , EBX
        _007C1D0D :
        MOV EDX, DWORD PTR SS : [ESP + 3Ch]
        MOV EAX, EDI
        SUB EAX, EDX
        SHR EAX, 1
        SUB EAX, EDX
        MOV ESI, EAX
        MOV EAX, EBX
        LEA EBX, DWORD PTR DS : [EDX + ESI]
        MOV EDX, DWORD PTR SS : [ESP + 40h]
        SUB EAX, EDX
        //MOV EDX,-10h
        MOV DWORD PTR SS : [ESP + 10h] , EDX
        MOV DWORD PTR SS : [ESP + 8h] , EAX
        MOV ECX, DWORD PTR SS : [ESP + 38h]
        MOV EDX, DWORD PTR SS : [ESP + 48h]
        LEA ESI, DWORD PTR DS : [ECX + EDX * 4h - 1B8h]
        CMP DWORD PTR DS : [ESI] , 0h
        JNZ short _007C1D56
        ADD ESI, 78h
        CMP DWORD PTR DS : [ESI] , 0h
        JNZ short _007C1D56
        ADD ESI, 78h
        CMP DWORD PTR DS : [ESI] , 0h
        JE _007C1EE3
        _007C1D56 :
        MOV EAX, DWORD PTR DS : [ESI]
        MOV EDX, DWORD PTR SS : [ESP + 3Ch]
        MOV DWORD PTR SS : [ESP + 24h] , EAX
        MOV EAX, EDI
        SUB EAX, EDX
        MOV EDX, -10h
        LEA ECX, DWORD PTR DS : [EDI - 198h]
        LEA EDX, DWORD PTR DS : [EDI - 1h]
        MOV DWORD PTR SS : [ESP + 1Ch] , 0h
        MOV DWORD PTR DS : [7A4038h] , 1C7h
        MOV DWORD PTR SS : [ESP + 2Ch] , EDX
        MOV DWORD PTR SS : [ESP + 28h] , ECX
        MOV DWORD PTR SS : [ESP + 4h] , EAX
        CALL Aoc10C_007C1EF0
        MOV EAX, DWORD PTR SS : [ESP + 24h]
        MOV EDX, DWORD PTR SS : [ESP + 3Ch]
        MOV ECX, DWORD PTR DS : [EAX + 0Ch]
        CMP DWORD PTR SS : [ESP + 20h] , 116h //copyed byte (on copy a partir de )
        JE short _007C1DBD
        MOV ESI, 0DAh
        LEA EBX, DWORD PTR DS : [EDI - 128h]
        MOV EDI, -26h
        LEA EBP, DWORD PTR DS : [EDX - 434h]
        JMP short _007C1DD3
        _007C1DBD :
        //MOV ESI, 119h//midle bar replication
        MOV ESI, 200h//midle bar replication
        LEA EBX, DWORD PTR DS : [EDI - 160h]
        MOV EDI, -2Ah
        LEA EBP, DWORD PTR DS : [EDX - 576h]
        _007C1DD3 :
        XOR EDX, EDX
        LEA EAX, DWORD PTR DS : [ESI - 1h]
        MOV DWORD PTR SS : [ESP + 1Ch] , EDX
        MOV DWORD PTR DS : [7A4038h] , 1C7h
        MOV DWORD PTR SS : [ESP + 2Ch] , EAX
        MOV DWORD PTR SS : [ESP + 28h] , EDX
        MOV DWORD PTR SS : [ESP + 4h] , EDX
        MOV EDX, DWORD PTR SS : [ESP + 44h]
        LEA EAX, DWORD PTR DS : [EBX + 40h]
        DEC EDX
        CMP ECX, EAX
        JL short _007C1E09
        CMP ECX, EDX
        JNZ short _007C1E18
        CALL Aoc10C_007C1F20
        JMP short _007C1E18
        _007C1E09 :
        //0x0500386
        //0x0651C48
        MOV ECX, DWORD PTR SS : [ESP + 38h]
        MOV DWORD PTR DS : [7A4004h] , ECX
        CALL Aoc10C_007C1EF0
        _007C1E18 :
        MOV EAX, DWORD PTR SS : [ESP + 24h]
        CMP DWORD PTR DS : [EAX + 0Ch] , ESI
        JL _007C1EE3
        CMP DWORD PTR DS : [EAX + 8h] , EBX
        JG _007C1EE3
        LEA EDX, DWORD PTR DS : [ESI + 30h]
        _007C1E31 :
        MOV DWORD PTR SS : [ESP + 1Ch] , 0h
        MOV DWORD PTR DS : [7A4038h] , 1C7h
        MOV DWORD PTR SS : [ESP + 2Ch] , EDX
        MOV DWORD PTR SS : [ESP + 28h] , ESI
        MOV DWORD PTR SS : [ESP + 4h] , EDI
        CALL Aoc10C_007C1F20
        ADD EDI, 30h
        ADD ESI, 30h
        ADD EBP, 30h
        LEA EDX, DWORD PTR DS : [ESI + 30h]
        CMP EDX, EBX
        JGE short _007C1EBE
        MOV DWORD PTR SS : [ESP + 1Ch] , 2h
        MOV DWORD PTR DS : [7A4038h] , 1C7h
        MOV DWORD PTR SS : [ESP + 2Ch] , EDX
        MOV DWORD PTR SS : [ESP + 28h] , ESI
        MOV DWORD PTR SS : [ESP + 4h] , EBP
        CALL Aoc10C_007C1F20//ici
        ADD EDI, 30h
        ADD ESI, 30h
        ADD EBP, 30h
        LEA EDX, DWORD PTR DS : [ESI + 30h]
        CMP EDX, EBX
        JLE short _007C1E31
        //0x0500386
        MOV EDX, EBX
        MOV DWORD PTR SS : [ESP + 1Ch] , 0h
        MOV DWORD PTR DS : [7A4038h] , 1C7h//position of top bar?
        MOV DWORD PTR SS : [ESP + 2Ch] , EDX
        MOV DWORD PTR SS : [ESP + 28h] , ESI
        MOV DWORD PTR SS : [ESP + 4h] , EDI
        CALL Aoc10C_007C1F20
        JMP short _007C1EE3
        _007C1EBE :
        MOV EDX, EBX
        MOV DWORD PTR SS : [ESP + 1Ch] , 2h
        MOV DWORD PTR DS : [7A4038h] , 1C7h//position of top bar?
        MOV DWORD PTR SS : [ESP + 2Ch] , EDX
        MOV DWORD PTR SS : [ESP + 28h] , ESI
        MOV DWORD PTR SS : [ESP + 4h] , EBP
        CALL Aoc10C_007C1F20
        _007C1EE3 :
        ADD ESP, 50h
        POP EBP
        POP EBX
        POP EDI
        POP ESI
        RETN
    }
}

DWORD Aoc10C_007C1C38 = (DWORD)f_Aoc10C_007C1C38;// 0x07C1C38;
//0x0500386
void __declspec(naked) ResizeslpInterface()
{
    __asm
    {
        PUSH ESI
        PUSH EDI
        PUSH EBX
        PUSH EBP
        SUB ESP, 30h
        MOV EDI, DWORD PTR DS : [ESI + 20h]
        MOV ECX, DWORD PTR DS : [ESI + 100Ch]
        //MOV ECX, DWORD PTR DS : [ESI + 1008h]
        MOV EDX, DWORD PTR DS : [EDI + 0C0h]
        MOV EBX, DWORD PTR DS : [EDI + 0D0h]
        MOV DWORD PTR DS : [7A4000h] , EDX //007A4000 = 795000
        MOV EAX, DWORD PTR DS : [EBX + 3Ch]
        MOV EDX, DWORD PTR DS : [EBX + 40h]
        MOV DWORD PTR DS : [7A4004h] , EAX
        MOV DWORD PTR DS : [7A4008h] , EDX
        MOV EDI, DWORD PTR DS : [ESI + 14h]
        MOV EBX, DWORD PTR DS : [ESI + 18h]
        MOV EBP, DWORD PTR DS : [ECX + 0Ch]
        LEA EAX, DWORD PTR DS : [EBX - 1h]
        LEA EDX, DWORD PTR DS : [EDI - 1h]
        MOV DWORD PTR DS : [7A4080h] , 0h
        MOV DWORD PTR DS : [7A4084h] , EAX
        MOV DWORD PTR DS : [7A4088h] , 0h
        MOV DWORD PTR DS : [7A408Ch] , EDX
        MOV DWORD PTR DS : [7A4038h] , 0h
        CMP EDI, 320h
        JE short _007C1BF5
        CMP EDI, 400
        JNZ short __007C1C38//age2_x1_.007C1C38
        CMP EBX, 300
        JL short __007C1C38//age2_x1_.007C1C38
        _007C1BF5 :
        MOV EDX, DWORD PTR SS : [EBP + 24h]
        MOV EAX, DWORD PTR SS : [EBP + 20h]
        PUSH 0h
        PUSH EDX
        PUSH EAX
        MOV EDX, DWORD PTR SS : [EBP + 30h]
        //top bar
        //PUSH 19h
        PUSH 100h
        PUSH EDX
        PUSH 0h
        PUSH 0h
        PUSH EBP//X
        CALL Aoc10C_007C1EF0//Aoc10C_007C1EF0
        //down bar
        MOV EDX, DWORD PTR SS : [EBP + 34h]
        MOV EAX, EBX
        MOV DWORD PTR DS : [7A4038h] , 1C7h
        SUB EAX, EDX
        MOV DWORD PTR SS : [ESP + 10h] , EDX
        MOV DWORD PTR SS : [ESP + 8h] , EAX
        CALL Aoc10C_007C1EF0//Aoc10C_007C1EF0
        ADD ESP, 50h
        POP EBP
        POP EBX
        POP EDI
        POP ESI
        RETN
        __007C1C38 :
        JMP[Aoc10C_007C1C38]

    }
}


DWORD _0065279C = 0x065279C;
void __declspec(naked) testFix()
{
    __asm
    {
        MOV DWORD PTR DS : [7A4018h] , EAX
        //00652799   > 3B57 0C        CMP EDX,DWORD PTR DS:[EDI+C]
        CMP EDI, 0F0000000h
        Jg force
        CMP EDX, DWORD PTR DS : [EDI + 0Ch]
        JMP _0065279C  
        force:
        MOV EDI,   DWORD PTR DS : [7A4004h]
        CMP EDX, DWORD PTR DS : [EDI + 0Ch]
        JMP _0065279C
    }
}
DWORD u_Cord_X;
DWORD u_Cord_Y;
void  wide()
{
 
    int V = 0;
    int H = 0;

    int cpt = 0;


 
    V = (int)u_Cord_Y;
    //LeaveCriticalSection(&cs_Cord_Y);
    //EnterCriticalSection(&cs_Cord_X);
    H = (int)u_Cord_X;
    //EnterCriticalSection(&cs_Cord_X);
 
    //Nop(0x04DF2D5, 6);
    //Nop(0x04DF2F8, 6);

 
    patchEXE(H, V);
 

}
//resize dyamicaly screen
//"map1280.bmp"
//004F66EE  |.^75 E5          \JNZ SHORT battlegr.004F66D5
DWORD _wide = (DWORD)wide;
DWORD EAX_wide;
DWORD ECX_wide;
 
DWORD _005C6230 = 0x05C6230;
DWORD _004F66FF = 0x04F66FF  ;

//0x04F66EE
void __declspec(naked)  u_AddWideScreenPanelreadXY()
{
    __asm {

        CALL _005C6230
        MOV EAX_wide, EAX
        MOV ECX_wide, ECX
        MOV EAX, DWORD PTR DS : [EDI + 18h]//Y            
        MOV u_Cord_Y, EAX
 
        MOV EAX, DWORD PTR DS : [EDI + 14h]//X
        MOV u_Cord_X, EAX

        call _wide
        MOV EAX, EAX_wide
        MOV ECX, ECX_wide
 
        JMP _004F66FF
 
    };
}



DWORD _004D998C = 0x04D998C;
DWORD _Res__X = (DWORD)GetSystemMetrics(SM_CXSCREEN);
DWORD _Res__Y = (DWORD)GetSystemMetrics(SM_CYSCREEN);
//0041BCC5     B9 00040000                  MOV ECX, 400

DWORD _0041BD2B = 0x041BD2B;
DWORD _getscreenEax = 0x041BD2B;
void __declspec(naked)  setScreenRes()
{
    __asm {
        /*	MOV ECX, _Res__Y
            MOV EDX, _Res__X
            MOV EDX, DWORD PTR DS : [6645C4]
            MOV EAX, DWORD PTR DS : [EDX + 24]
            MOV EAX, DWORD PTR DS : [EAX + 8F4]
            CMP EAX, 320*/

            //MOV ECX, _u_Cord_X
            //MOV EDX, _u_Cord_Y
            //MOV u_screenSaveEDX, EDX
            //MOV EDX, DWORD PTR DS : [6645C4h]
            //MOV EAX, DWORD PTR DS : [EDX + 24h]
            //MOV EDX, _u_Cord_X
            //MOV  DWORD PTR DS : [EAX + 8F4h] , EDX
            //MOV EAX, _u_Cord_Y
            //MOV  DWORD PTR DS : [EAX + 8F8h] , EDX


        MOV EAX, DWORD PTR DS : [EBX + 24h]
        MOV ECX, _Res__X
        MOV DWORD PTR DS : [EAX + 8F4h] , ECX // 320h
        MOV ECX, DWORD PTR DS : [EBX + 24h]
        MOV _getscreenEax, EAX
        MOV EAX, _Res__Y
        MOV DWORD PTR DS : [ECX + 8FCh] , EAX//258
        MOV  _Res__Y, EAX
        JMP _0041BD2B



    }
}
 
//void stretch( char*data, int size)
//{
//    SLP slp;
//    slp.load((unsigned char*)data, size);
// 
//    slp.stretch(u_Cord_X, u_Cord_Y, id);
//}
//004D4FE8  |>-E9 631E8F73    ||JMP efpatch.73DC6E50

void __declspec(naked)  hookwide()
{
    __asm {
        MOV EAX, DWORD PTR DS : [ECX + 50h]
        ADD EAX, ECX
        CMP ESI, EAX
        JE short _73DC6E6A//efpatch.73DC6E6A
        MOV EAX, DWORD PTR SS : [ESP + 10h]
        MOV EDX, DWORD PTR DS : [ESI]
        CMP EDX, EAX
        JNZ short _73DC6E6A//efpatch.73DC6E6A
        MOV EDX, 4D5020h
        JMP EDX
        _73DC6E6A:
        MOV EDX, 4D4FF2h
        JMP EDX
    }
}

void wideScreenHook()
{
    //004D4FE8 | > -E9 631E8F73 || JMP efpatch.73DC6E50
    InjectHook((void*)0x04F66FA, hookwide, PATCH_JUMP);


    //004F66EE  |.^75 E5          \JNZ SHORT battlegr.004F66D5
    InjectHook((void*)0x04F66FA , u_AddWideScreenPanelreadXY, PATCH_JUMP);

    ////InjectHook(0x0652794 , testFix, PATCH_JUMP);
	//004F66F0  |. BA 2AD00000    MOV EDX,0D02A


	////resize screen by [SWG]_RvA_'s
    //todo change dybnamically x and y
    //patchEXE(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));

    //liste screen controle on game 
    //00459DB0  |. 6A 69          |PUSH 69                                 ; |Arg4 = 00000069
    writeByte(0x0459DB0+1, 0x6E);
    //00459DDF  |. 6A 46          |PUSH 46                                 ; |Arg3 = 00000046
    writeByte(0x0459DDF+1, 0x4B);
    //0045ACFF   . 74 23          JE SHORT battlegr.0045AD24
    writeByte(0x045ACFF, 0x66);
    Nop(0x045ACFF+1, 1);
    //0045A29F  |. 8B6C24 4C      MOV EBP,DWORD PTR SS:[ESP+4C]
    InjectHook((void*)0x045A29F, addWidescreenControl1, PATCH_JUMP);
    ////0045AC80   > 8B8E 88080000  MOV ECX,DWORD PTR DS:[ESI+888]
    InjectHook((void*)0x045AC80, addWidescreenControl2, PATCH_JUMP);

    //resize slp interface
    //00522356 
    //00522351   . 68 68235200    PUSH age2_x1_.00522368
    //00500398   . 8B8E A4100000  MOV ECX,DWORD PTR DS:[ESI+10A4]
    //push 00500398
    //////00500381     68 98035000    PUSH battlegr.00500398
    ////BYTE push[5]{ 0x68, 0x98, 0x03, 0x50,0x00};
    ////writeData((DWORD)0x0500381, push, 5);
    //////00522354   . 8B8E 0C100000  MOV ECX,DWORD PTR DS:[ESI+100C]
    //////00500386     90             NOP
    ////InjectHook((void*)0x0500386, ResizeslpInterface, PATCH_JUMP);
    //005252BB   .-E9 50C32900    JMP age2_x1_.007C1610
    //InjectHook(0x05252BB, fixRecordInterface, PATCH_JUMP);
    //0051FBBF     EB 7D          JMP SHORT age2_x1.0051FC3E
    //	0051FBC1     90             NOP
    //	0051FBC2     90             NOP
    //	0051FBC3     90             NOP
    //	0051FBC4     90             NOP
    //	0051FBC5     90             NOP
    //	0051FBC6     90             NOP
    //	0051FBC7     90             NOP
    //writeByte(0x051FBBF, 0xEB);
    //writeByte(0x51FBC0, 0x7D);
    //Nop(0x051FBC1, 7);
    //no work :(
    // 00543201  |> 8B15 60FA7700  MOV EDX,DWORD PTR DS:[77FA60]
 
    //InjectHook(0x0500393 , parseSLP, PATCH_CALL);
    ////InjectHook(0x0543238  ,stretch, PATCH_CALL);
    ////InjectHook(0x05433F4  ,stretch, PATCH_CALL);
    ////InjectHook(0x060EB83  ,stretch, PATCH_CALL);
    ////InjectHook(0x060EBDD  ,stretch, PATCH_CALL);
    ////InjectHook(0x060F3AF  ,stretch, PATCH_CALL);

    //004FDAF6  |. 7C 27          JL SHORT battlegr.004FDB1F


}






//analyzie
//00632D34.A9 00800000    TEST EAX, 8000   == 32768 check slp strach function
//00632D39   . 0F85 81090000  JNZ age2_x1_.006336C0
//
//we jump

//if (edge[i][j].right == -32768)
//edge[i][j].right = 0;
//00651BC0   $ 55             PUSH EBP



