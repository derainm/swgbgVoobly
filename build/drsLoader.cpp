// 005E4B73 | .E8 9800EFFF    CALL battlegr.004D4C10; \battlegr.004D4C10
#include "drsLoader.h"
#include <fstream>      // std::ifstream, std::ofstream
#include "drsfile.h"
#include "slp.h"
#include "MemoryMgr.h"
#include <iostream>
 
//using namespace std;
const char aSwbg[] = "swbg";

/*char* aDrsWide[] =
{
    "sounds_x1.drs",
    "sounds_x2.drs",
    "graphics.drs",
    "graphics_x1.drs",
    "graphics_x2.drs",
    "terrain.drs",
    "terrain_x1.drs",
    "terrain_x2.drs",
    "wide.drs",
    "interfac_x2.drs",
    "interfac.drs",
    "interfac_x1.drs",
    "gamedata_x2.drs"
};

char* aDrsNoWide[] =
{
    "sounds_x1.drs",
    "sounds_x2.drs",
    "graphics.drs",
    "graphics_x1.drs",
    "graphics_x2.drs",
    "terrain.drs",
    "terrain_x1.drs",
    "terrain_x2.drs",
    "interfac_x2.drs",
    "interfac.drs",
    "interfac_x1.drs",
    "gamedata_x2.drs"
};*/



//const char* aDrsWide[] =
//{
//    "sounds_x1.drs",
//    "sounds_x2.drs",
//    "graphics_p1.drs",
//    "graphics_x1_p1.drs",
//    "graphics_x2.drs",
//    "terrain_p1.drs",
//    "terrain_x1_p1.drs",
//    "terrain_x2.drs",
//    "wide_p1.drs",
//    "interfac_x2.drs",
//    "interfac_p1.drs",
//    "interfac_x1_p1.drs",
//    "gamedata_x2.drs"
//};

////const char* aaDrsNoWide[] =
////{
////    "sounds_x1.drs",
////    "sounds_x2.drs",
////    "graphics_p1.drs",
////    "graphics_x1_p1.drs",
////    "graphics_x2.drs",
////    "terrain_p1.drs",
////    "terrain_x1_p1.drs",
////    "terrain_x2.drs",
////    "interfac_x2.drs",
////    "interfac_p1.drs",
////    "interfac_x1_p1.drs",
////    "gamedata_x2.drs"
////};
////
////const char* aaDrsCCWide[] =
////{
////    "sounds_x1.drs",
////    "graphics.drs",
////    "graphics_x1.drs",
////    //"terrgrid.drs",
////    "terrain.drs",
////    "terrain_x1.drs",
////    "wide.drs",
////    "interfac.drs",
////    "interfac_x1.drs",
////    "gamedata_x1.drs"
////};
const char* aaDrsWide[] =
{
    "sounds_x1.drs",
    "..\\Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\sounds_x2.drs",
    "..\\Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\graphics_p1.drs",
    "..\\Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\graphics_x1_p1.drs",
    "..\\Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\graphics_x2.drs",
    "..\\Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\terrain_p1.drs",
    "..\\Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\terrain_x1_p1.drs",
    "..\\Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\terrain_x2.drs",
    //"Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\wide.drs",// widescreen
    "..\\Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\wide_p2.drs",
	"..\\Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\wide_p1.drs",// widescreen
    "..\\Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\interfac_x2.drs",
    //"Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Datainterfac_p1.drs",
    //"Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Datainterfac_x1_p1.drs",
	"..\\Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\interfac_p1.drs",
	"..\\Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\interfac_x1_p1.drs",
    "..\\Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\gamedata_x2.drs"
};
/*
const char* aaDrsWide[] =
{
	"sounds_x1.drs",
	"sounds_x2.drs",
	"graphics_p1.drs",
	"graphics_x1_p1.drs",
	"graphics_x2.drs",
	"terrain_p1.drs",
	"terrain_x1_p1.drs",
	"terrain_x2.drs",
	"wide_p1.drs",
	"interfac_x2.drs",
	"interfac_p1.drs",
	"interfac_x1_p1.drs",
	"gamedata_x2.drs"
};*/
int paramCntr = 1;

const int nnDrsWide = sizeof(aaDrsWide) / sizeof(aaDrsWide[0]);
//const int nnDrsNoWide = sizeof(aaDrsNoWide) / sizeof(aaDrsNoWide[0]);
//const int nnDrsCCWide = sizeof(aaDrsCCWide) / sizeof(aaDrsCCWide[0]);

int nnDrs;
const char** aaDrs;

__declspec(naked) void aloadDRS()
{
    __asm
    {
        xor eax, eax
        mov     edx, paramCntr
        test    edx, edx
        setnz   al
        sub     edx, eax
        mov     paramCntr, edx
        push    eax
        mov     eax, [ebp + 24h]
        add     eax, 1467h
        push    eax
        mov     edx, offset aSwbg
        mov     eax, 4D4C10h
        call    eax
        ret
    }
}

__declspec(naked) void aloadDRSHook() //005E4B78
{
    __asm
    {
        push    edi
        push    esi

        mov     edi, aaDrs
        mov     eax, nnDrs
        lea     esi, [edi + eax * 4]
        cont:
        cmp     edi, esi
            jnb     end
            mov     ecx, [edi]
            add     edi, 4
            call    aloadDRS
            jmp     cont
            end :
        pop     esi
            pop     edi
            mov     ecx, 005E4C46h
            jmp     ecx
    }
}

__declspec(naked) void adrsHeaderEnd() //004D4FE8
{
    __asm
    {
        mov     eax, [ecx + 50h]
        add     eax, ecx
        cmp     esi, eax
        jz      _outside
        mov     eax, [esp + 10h]
        mov     edx, [esi]
        cmp     edx, eax
        jnz     _outside
        mov     edx, 004D5020h
        jmp     edx
        _outside :
        mov     edx, 004D4FF2h
            jmp     edx
    }
}
int findRectOffset1(void* drsRects, const char* itemname)
{
	int i = 0;
	size_t len = strlen(itemname);
	while (memcmp(itemname, (char*)drsRects + i, len) != 0)
		i++;
	return i;
}


void patchRect(int x,
	int y,
	const char* itemName, //name of the control, open 53290 in interfac.drs for details
	bool addX, //control needs to be moved horizontally
	bool addY, //control needs to be moved vertically
	bool addW, //control needs to be stretched horisontally
	bool addH, //control needs to be stretched vertically
	int* size, //returns the new size of the DRS item
	void* drsRects)
{
	//log("Patching rect \"%s\", params: %d, %d, %d, %d",
	//    itemName, addX, addY, addW, addH);

	char* endbuf = (char*)malloc(4096);

	int X800; //see 53290 in interfac.drs to understand how this works
	int Y800;
	int W800;
	int H800;
	int X1024;
	int Y1024;
	int W1024;
	int H1024;
	int X1280;
	int Y1280;
	int W1280;
	int H1280;
	char scanArg[128];
	char oldRects[128];
	char newRects[128];
	sprintf(scanArg, "%s\t%%d\t%%d\t%%d\t%%d\t%%d\t%%d\t%%d\t%%d\t%%d\t%%d\t%%d\t%%d\t%%s", itemName);
	sscanf((char*)drsRects + findRectOffset1(drsRects, itemName), scanArg,
		&X800, &Y800, &W800, &H800,
		&X1024, &Y1024, &W1024, &H1024,
		&X1280, &Y1280, &W1280, &H1280,
		endbuf);
	sprintf(oldRects, "\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t", //tab value tab value...
		X800, Y800, W800, H800,
		X1024, Y1024, W1024, H1024,
		X1280, Y1280, W1280, H1280);
	if (addX)
		if (y >= 1024)
			X1280 += x - 1280;
		else if (y >= 768)
			X1024 += x - 1024;
		else
			exit(1);
	if (addY)
		if (y >= 1024)
			Y1280 += y - 1024;
		else if (y >= 768)
			Y1024 += y - 768;
		else
			exit(1);
	if (addW)
		if (y >= 1024)
			W1280 += x - 1280;
		else if (y >= 768)
			W1024 += x - 1024;
		else
			exit(1);
	if (addH)
		if (y >= 1024)
			H1280 += y - 1024;
		else if (y >= 768)
			H1024 += y - 768;
		else
			exit(1);
	sprintf(newRects, "\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t",
		X800, Y800, W800, H800,
		X1024, Y1024, W1024, H1024,
		X1280, Y1280, W1280, H1280);

	int dst;
	int src;
	int n;

	if (strlen(oldRects) != strlen(newRects)) //adjust data...
	{
		dst = (int)drsRects + findRectOffset1(drsRects, itemName) + strlen(itemName) + strlen(newRects) - strlen(oldRects);
		src = (int)drsRects + findRectOffset1(drsRects, itemName) + strlen(itemName);
		n = *size - findRectOffset1(drsRects, itemName) + strlen(itemName);
		memmove((void*)dst, (void*)src, n);
		*size += strlen(newRects) - strlen(oldRects);
		memcpy((void*)src, newRects, strlen(newRects));
	}
	else //don't adjust data...
	{
		dst = (int)drsRects + findRectOffset1(drsRects, itemName) + strlen(itemName);
		memcpy((void*)dst, newRects, strlen(newRects));
	}

	free(endbuf);
}
#define RESOLUTION_TOOL_VERSION 100006
//004F66F5  |. B9 240E6900    MOV ECX,battlegr.00690E24                ;  ASCII "screen_coords.txt"


void placeSLP(DRS* x0, DRS* x1, DRS* x2, DRS* wide_x2, DRS* target, int id, bool wide)
{
	int size;
	void* data;
	if (wide)
	{
		data = wide_x2->getFile(id, &size);
		if (!data)
		{
			char err[0x100];
			sprintf(err, "Cannot load SLP %d from DRS", id);
			//log(err);
			MessageBox(NULL, err, "Error", MB_ICONERROR);
			exit(0);
		}
	}
	else
	{
		data = x2->getFile(id, &size);
		if (!data)
		{
			data = x1->getFile(id, &size);
			if (!data)
			{
				data = x0->getFile(id, &size);
				if (!data)
				{
					char err[0x100];
					sprintf(err, "Cannot load SLP %d from DRS", id);
					//log(err);
					MessageBox(NULL, err, "Error", MB_ICONERROR);
					exit(0);
				}
			}
		}
	}
	target->addFile(data, size, id, DRS_SLP);
	free(data);
}


void patchResRects(int x, int y, DRS* drs)
{


	int size;
	//DRS drs;
	//drs->setFileName("..\Voobly Mods\SWBGCC\Data Mods\Expanding Fronts 1.4.1\\Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\wide.drs");
	//DRS* drs2 = new DRS;
	//drs2->loadDRS("data\\wide.drs");
	//void* drsResStr = drs2->getFile(RESOLUTION_TOOL_VERSION, &size);
	//delete drs2;

	DRS x1;
	if (!x1.loadDRS("Data\\interfac_x1.drs"))
	{
		char err[0x100];
		sprintf(err, "Cannot load interfac_x1.drs");
		//log(err);
		MessageBox(NULL, err, "Error", MB_ICONERROR);
		exit(0);
	}
	void* drsRects2 = x1.getFile(53290, &size);
	if (!drsRects2)
	{
		char err[0x100];
		sprintf(err, "Cannot load BIN 53290 from interfac_x1.drs");
		//log(err);
		MessageBox(NULL, err, "Error", MB_ICONERROR);
		exit(0);
	}
	void* drsRects = malloc(size * 2);
	memcpy(drsRects, drsRects2, size);
	free(drsRects2);


	patchRect(x, y, "ToolBox", 0, 0, 1, 0, &size, drsRects);
	patchRect(x, y, "Main Viewport with toolbox", 0, 0, 1, 1, &size, drsRects);
	patchRect(x, y, "Main Viewport w/o toolbox", 0, 0, 1, 1, &size, drsRects);
	patchRect(x, y, "Inventory Panel", 1, 1, 0, 0, &size, drsRects);
	patchRect(x, y, "Map View", 1, 1, 0, 0, &size, drsRects);
	patchRect(x, y, "Age Panel", 0, 1, 1, 0, &size, drsRects);
	patchRect(x, y, "Objectives Changed Text", 1, 0, 0, 0, &size, drsRects);
	patchRect(x, y, "FPS Panel", 1, 1, 0, 0, &size, drsRects);
	patchRect(x, y, "Object Panel", 0, 1, 1, 0, &size, drsRects);
	patchRect(x, y, "Action Buttons", 0, 1, 0, 0, &size, drsRects);
	patchRect(x, y, "Objectives Button", 1, 1, 0, 0, &size, drsRects);
	patchRect(x, y, "Tech Tree Button", 1, 1, 0, 0, &size, drsRects);
	patchRect(x, y, "Chat Button", 1, 1, 0, 0, &size, drsRects);
	patchRect(x, y, "Diplomacy Button", 1, 1, 0, 0, &size, drsRects);
	patchRect(x, y, "Menu Button", 1, 1, 0, 0, &size, drsRects);
	patchRect(x, y, "Flare Button", 1, 1, 0, 0, &size, drsRects);
	patchRect(x, y, "Idle Villager Button", 1, 1, 0, 0, &size, drsRects);
	patchRect(x, y, "Score Button", 1, 1, 0, 0, &size, drsRects);
	patchRect(x, y, "Popup Help Button", 1, 1, 0, 0, &size, drsRects);
	patchRect(x, y, "Advanced Button", 1, 1, 0, 0, &size, drsRects);
	patchRect(x, y, "Normal Map Button", 1, 1, 0, 0, &size, drsRects);
	patchRect(x, y, "Combat Map Button", 1, 1, 0, 0, &size, drsRects);
	patchRect(x, y, "Resource Map Button", 1, 1, 0, 0, &size, drsRects);
	patchRect(x, y, "Toggle MiniMap Terrain", 1, 1, 0, 0, &size, drsRects);

 
	drs->addFile(drsRects, size, 53290, DRS_BIN); //"bina"
 
	free(drsRects);
}

void parseSLP(DRS* x0, DRS* x1, DRS* x2, DRS* target, int id, int x, int y)
{
	int size;
	void* data;
	data = x2 ? x2->getFile(id, &size) : NULL;
	if (!data)
	{
		data = x1 ? x1->getFile(id, &size) : NULL;
		if (!data)
		{
			data = x0 ? x0->getFile(id, &size) : NULL;
			if (!data)
			{
				char err[0x100];
				sprintf(err, "Cannot load SLP %d from DRS", id);
				//log(err);
				MessageBox(NULL, err, "Error", MB_ICONERROR);
				exit(0);
			}
		}
	}
	SLP slp;
	slp.load((unsigned char*)data, size);
	free(data);
	if (id == 50341)
		slp.stretch_techtree(x, y);
	else
		slp.stretch(x, y, id);
	unsigned char* new_slp;
	int new_size = size;
	new_slp = slp.optimize(&new_size, true);
	target->addFile(new_slp, new_size, id, DRS_SLP);
	free(new_slp);
}


void patchResolution(int x, int y, DRS* drs)
{
	//log("Resolution patch started, %dx%d", x, y);
	//log("Patching rects...");

	patchResRects(x, y, drs);

	//log("Updating resolution id");
	char resStr[20];
	sprintf(resStr, "%dx%d", x, y);
	drs->addFile(resStr, strlen(resStr) + 1, RESOLUTION_TOOL_VERSION, DRS_BIN); //bina

	//log("Stretching SLPs...");

	//#ifdef _CHEATDLL_CC
	DRS x0_cc; x0_cc.loadDRS("data\\INTERFAC.DRS");
	DRS x1_cc; x1_cc.loadDRS("data\\interfac_x1.drs");
	//#else

	DRS x0; x0.loadDRS("Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\interfac_p1.DRS");
	DRS x1; x1.loadDRS("Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\interfac_x1_p1.drs");
	//#endif
	DRS x2; x2.loadDRS("Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\interfac_x2.drs");
	DRS wide_x2; wide_x2.loadDRS("Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\widescrn_x2.drs");

	//tech tree
	parseSLP(&x0, &x1, &x2, drs, 50341, x, y);

	if (y >= 1024)
	{
		parseSLP(&x0_cc, &x1_cc, NULL, drs, 51141, x, y);
		parseSLP(&x0_cc, &x1_cc, NULL, drs, 51142, x, y);
		parseSLP(&x0_cc, &x1_cc, NULL, drs, 51143, x, y);
		parseSLP(&x0_cc, &x1_cc, NULL, drs, 51144, x, y);
		parseSLP(&x0_cc, &x1_cc, NULL, drs, 51145, x, y);
		parseSLP(&x0_cc, &x1_cc, NULL, drs, 51146, x, y);

		parseSLP(&x0_cc, &x1_cc, NULL, drs, 51147, x, y);
		parseSLP(&x0_cc, &x1_cc, NULL, drs, 51148, x, y);
	}
	else if (y >= 768)
	{
		parseSLP(&x0_cc, &x1_cc, NULL, drs, 51121, x, y);
		parseSLP(&x0_cc, &x1_cc, NULL, drs, 51122, x, y);
		parseSLP(&x0_cc, &x1_cc, NULL, drs, 51123, x, y);
		parseSLP(&x0_cc, &x1_cc, NULL, drs, 51124, x, y);
		parseSLP(&x0_cc, &x1_cc, NULL, drs, 51125, x, y);
		parseSLP(&x0_cc, &x1_cc, NULL, drs, 51126, x, y);

		parseSLP(&x0_cc, &x1_cc, NULL, drs, 51127, x, y);
		parseSLP(&x0_cc, &x1_cc, NULL, drs, 51128, x, y);
	}
	drs->writeDRS();

	drs->setFileName("Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\wide_p1.drs");

	//50032 - edit small
	//50033 - edit medium
	//50034 - edit large
	//50100 - load small
	//50101 - load medium
	//50102 - load large

//#ifndef _CHEATDLL_CC
	if (x >= 1920)
	{
		placeSLP(&x0, &x1, &x2, &wide_x2, drs, 50032, false);
		placeSLP(&x0, &x1, &x2, &wide_x2, drs, 50033, false);
		placeSLP(&x0, &x1, &x2, &wide_x2, drs, 50034, true);
		placeSLP(&x0, &x1, &x2, &wide_x2, drs, 50100, false);
		placeSLP(&x0, &x1, &x2, &wide_x2, drs, 50101, false);
		placeSLP(&x0, &x1, &x2, &wide_x2, drs, 50102, true);
	}
	else
	//	//#endif
	{
		placeSLP(&x0, &x1, &x2, &wide_x2, drs, 50032, false);
		placeSLP(&x0, &x1, &x2, &wide_x2, drs, 50033, false);
		placeSLP(&x0, &x1, &x2, &wide_x2, drs, 50034, false);
		placeSLP(&x0, &x1, &x2, &wide_x2, drs, 50100, false);
		placeSLP(&x0, &x1, &x2, &wide_x2, drs, 50101, false);
		placeSLP(&x0, &x1, &x2, &wide_x2, drs, 50102, false);
	}

	if (y >= 1024)
	{
		parseSLP(&x0, &x1, &x2, drs, 51141, x, y);
		parseSLP(&x0, &x1, &x2, drs, 51142, x, y);
		parseSLP(&x0, &x1, &x2, drs, 51143, x, y);
		parseSLP(&x0, &x1, &x2, drs, 51144, x, y);
		parseSLP(&x0, &x1, &x2, drs, 51145, x, y);
		parseSLP(&x0, &x1, &x2, drs, 51146, x, y);

		parseSLP(&x0, &x1, &x2, drs, 51147, x, y);
		parseSLP(&x0, &x1, &x2, drs, 51148, x, y);

		//#ifndef _CHEATDLL_CC
		parseSLP(&x0, &x1, &x2, drs, 51149, x, y);
		parseSLP(&x0, &x1, &x2, drs, 51150, x, y);
		parseSLP(&x0, &x1, &x2, drs, 51151, x, y);
		parseSLP(&x0, &x1, &x2, drs, 51152, x, y);
		//#endif
	}
	else if (y >= 768)
	{
		parseSLP(&x0, &x1, &x2, drs, 51121, x, y);
		parseSLP(&x0, &x1, &x2, drs, 51122, x, y);
		parseSLP(&x0, &x1, &x2, drs, 51123, x, y);
		parseSLP(&x0, &x1, &x2, drs, 51124, x, y);
		parseSLP(&x0, &x1, &x2, drs, 51125, x, y);
		parseSLP(&x0, &x1, &x2, drs, 51126, x, y);

		parseSLP(&x0, &x1, &x2, drs, 51127, x, y);
		parseSLP(&x0, &x1, &x2, drs, 51128, x, y);

		//#ifndef _CHEATDLL_CC
		parseSLP(&x0, &x1, &x2, drs, 51129, x, y);
		parseSLP(&x0, &x1, &x2, drs, 51130, x, y);
		parseSLP(&x0, &x1, &x2, drs, 51131, x, y);
		parseSLP(&x0, &x1, &x2, drs, 51132, x, y);
		//#endif
	}

	drs->writeDRS();

	//log("Resolution patch successfull");
}

void patchInterfaceSlp()
{
	int size;
	DRS drs;
	drs.setFileName("Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\wide.drs");
	DRS* drs2 = new DRS;
	drs2->loadDRS("Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\wide.drs");
	void* drsResStr = drs2->getFile(RESOLUTION_TOOL_VERSION, &size);
	delete drs2;

	patchResolution(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), &drs);
}
bool patchEXErva(int X, int Y) //needs to be completed...
{
	//log("Patching EXE for resolution %dx%d...", X, Y);

	if (Y >= 1024)
	{
		writeDwordF(0x24B66, Y); //ok
		writeDwordF(0x24BB3, X); //ok
		writeDwordF(0x261FD, Y); //ok
		writeDwordF(0x2623A, X); //ok
		writeDwordF(0x2680C, Y); //ok
		writeDwordF(0x26845, X); //ok
		//writeDwordF(0x290A8, Y); //probably not, try removing !!!
		writeDwordF(0x2AA3E, X); //ok
		writeDwordF(0x2AA52, X - 340); //could be
		writeDwordF(0x5A365, X); //ok
		writeDwordF(0x5A3CE, X); //ok
		writeDwordF(0x5ACBA, X); //ok
		writeDwordF(0x5ACBF, Y); //ok
		writeDwordF(0x5ACFB, X + 1); //ok
		writeDwordF(0x639FB, Y); //ok
		writeDwordF(0x63B9E, Y + 1); //mm ok
		writeDwordF(0x63E9F, Y); //ok
		//float hMul = (float)Y / 600;
		//hMul = 0;
		//writeDword (0x00463EAB, *(int*)&hMul);
		writeDwordF(0x6A916, X); //ok
		//writeDwordF(0x6A920, Y - 98); // TECH TREE ~!!                     voobly
		writeDwordF(0x70D36, X); //ok
		writeDwordF(0x70DFB, X); //ok
		writeDwordF(0x70E04, Y); //ok
		writeDwordF(0x70E16, X + 1); //ok
		writeDwordF(0x70E1F, Y + 1); //ok
		writeDwordF(0x710D4, X); //ok
		writeDwordF(0x710DB, X + 1); //check these 4, probably fine
		writeDwordF(0x7114B, X + 1);
		writeDwordF(0x711CD, X + 1);
		writeDwordF(0x71247, X + 1);
		//writeDwordF(0xA9411, X); //almost definitely wrong !!!             voobly
		writeDwordF(0xB7E39, X); //might be ok
		//writeDwordF(0xBE147, X); //almost definitely wrong !!!             voobly
		writeDwordF(0xF670C, X); //ok
		writeDwordF(0xFDAF2, X + 1); //mm ok
		writeDwordF(0xFDAFB, Y + 1); //mm ok
		writeDwordF(0xFDB20, X); //ok
		writeDwordF(0xFDB29, Y); //ok
		writeDwordF(0x1003A8, X); //ok
		writeDwordF(0x1003D5, X); //ok
		writeDwordF(0x1003E3, X - 298); //some item icon, check
		writeDwordF(0x1003E8, Y - 340);
		//writeDwordF(0x1003E3, Y-42); //some item icon, old ver
		//writeDwordF(0x1003E8, X-340);
		writeDwordF(0x102852, X); //rec game UI
		writeDwordF(0x10285E, Y - 224); //rec game UI
		writeDwordF(0x10C987, X); //ok
		writeDwordF(0x10E4CD, X); //ok
		writeDwordF(0x10E4D2, Y); //ok
		writeDwordF(0x10EDCC, X); //weird, likely OK
		writeDwordF(0x1D853F, X); //most likely
		writeDwordF(0x1D98E9, X); //likely OK
		//writeDwordF(0x1F6757, X); //not resolution                            voobly
	}
	else if (Y >= 768)
	{
		writeDwordF(0x24B66, X); //ok
		writeDwordF(0x24BAC, Y); //ok
		writeDwordF(0x24BB3, X + 1); //ok
		writeDwordF(0x261FD, X); //ok
		writeDwordF(0x26217, Y); //ok
		writeDwordF(0x2623A, X + 1); //not needed?
		writeDwordF(0x2680C, X); //ok
		writeDwordF(0x2683B, Y); //ok
		writeDwordF(0x26845, X + 1); //not needed?
		//writeDwordF (0x290A8, X); //test. not res?                           voobly
		writeDwordF(0x2AA37, X); //ok
		writeDwordF(0x2AA3E, X + 1); //not needed?
		writeDwordF(0x2AA59, X - 274); //-> should be ok
		writeDwordF(0x5A35E, X); //ok
		writeDwordF(0x5A365, X + 1); //not needed?
		writeDwordF(0x5A3AA, X); //ok
		writeDwordF(0x5A3CE, X + 1); //not needed?
		writeDwordF(0x5AC9F, X); //ok
		writeDwordF(0x5ACA4, Y); //ok
		writeDwordF(0x5ACBA, X + 1); //not needed?
		writeDwordF(0x5ACBF, Y + 1);
		writeDwordF(0x5ACFB, X + 2); //?
		writeDwordF(0x63923, Y); //ok
		writeDwordF(0x639FB, Y + 1); //block higher res
		writeDwordF(0x63B9E, Y + 2); //block higher res
		writeDwordF(0x63E85, Y); //ok
		writeDwordF(0x63E9F, Y + 1); //block higher res
		writeDwordF(0x6A90E, X); //ok
		writeDwordF(0x6A916, X + 1); //block higher res
		//writeDwordF(0x6A930, Y - 103); // TECH TREE ~!!
		writeDwordF(0x70D2B, X); //ok
		writeDwordF(0x70D36, X + 1); //block higher res
		writeDwordF(0x70DE0, X); //ok
		writeDwordF(0x70DE9, Y); //ok
		writeDwordF(0x70DFB, X + 1); //block higher res
		writeDwordF(0x70E04, Y + 1); //--
		writeDwordF(0x70E16, X + 2); //--
		writeDwordF(0x70E1F, Y + 2); //--
		writeDwordF(0x70EB5, X); //ok
		writeDwordF(0x70EBE, Y); //ok
		writeDwordF(0x70F5D, X); //ok
		writeDwordF(0x70F66, Y); //ok
		writeDwordF(0x7100B, X); //ok
		writeDwordF(0x71014, Y); //ok
		writeDwordF(0x7107E, X); //ok
		writeDwordF(0x710D4, X + 1); //block higher res
		writeDwordF(0x710DB, X + 2); //block higher res
		writeDwordF(0x71144, X); //ok?
		writeDwordF(0x7114B, X + 2); //block higher res
		writeDwordF(0x711C6, X); //ok?
		writeDwordF(0x711CD, X + 2); //block higher res
		writeDwordF(0x71240, X); //ok?
		writeDwordF(0x71247, X + 2); //block higher res
		//writeDwordF(0xA9411, X+1); //not res
		writeDwordF(0xB7E14, X); //ok
		writeDwordF(0xB7E39, X + 1); //ok
		//writeDwordF(0xBE147, X+1); //not res
		writeDwordF(0xF6705, X); //ok
		writeDwordF(0xF670C, X + 1); //block higher res
		writeDwordF(0xFDAF2, X + 2); //not needed?
		writeDwordF(0xFDAFB, Y + 2);
		writeDwordF(0xFDB20, X + 1);
		writeDwordF(0xFDB29, Y + 1);
		writeDwordF(0xFDB6C, X); //ok
		writeDwordF(0xFDB75, Y); //ok
		//writeDwordF(0x1003A8, X+1); //test!!!         (!!!)
		writeDwordF(0x1003D5, X + 1); //ok
		writeDwordF(0x1003FD, X); //ok
		//writeDwordF(0x1003E3:    D6    57
		//writeDwordF(0x1003E8:    AC    0D
		writeDwordF(0x1003FD, X); //ok
		writeDwordF(0x10040B, Y - 35); //ok, but test
		//writeDwordF(0x100410, X  //same as above
		writeDwordF(0x102852, X + 1); //ok
		writeDwordF(0x102865, X); //rec game UI
		writeDwordF(0x102871, Y - 181); //rec game UI
		writeDwordF(0x10C94A, X); //should be ok
		writeDwordF(0x10C987, X + 1); //block higher res
		writeDwordF(0x10E4B2, X); //ok
		writeDwordF(0x10E4B7, Y); //ok
		writeDwordF(0x10E4CD, X + 1); //block higher res
		writeDwordF(0x10E4D2, Y + 1); //block higher res
		writeDwordF(0x10EDC5, X); //ok
		writeDwordF(0x10EDCC, X + 1); //ok
		writeDwordF(0x1D8529, X); //ok
		writeDwordF(0x1D853F, X + 1); //ok
		writeDwordF(0x1D98DA, X);
		writeDwordF(0x1D98E9, X + 1);
		//writeDwordF(0x1F6757, X+1); //not res
	}
	else
	{
		MessageBox(0, "Resolutions lower than 768V are not supported", "Error", MB_ICONERROR);
	}

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


void setDRSLoadHooks()
{
	CopyFile("Voobly Mods\\SWBGCC\\Patches\\efpatch\\interfac_p1.drs", "Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\interfac_p1.drs", true);
	CopyFile("Voobly Mods\\SWBGCC\\Patches\\efpatch\\interfac_x1.drs", "Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\interfac_x1.drs", true);
	CopyFile("Voobly Mods\\SWBGCC\\Patches\\efpatch\\interfac_x1_p1.drs", "Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\interfac_x1_p1.drs", true);
	CopyFile("Voobly Mods\\SWBGCC\\Patches\\efpatch\\interfac_x2.drs", "Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\interfac_x2.drs", true);
	patchInterfaceSlp();
	CopyFile("Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\Data\\terrain.txt", "Data\\terrain.txt", true);

	//Sleep(500);
	patchEXErva(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
	// 
	// 
	//string s = e.Serialize(&ser);
	//MessageBoxA(0, s.c_str(), 0, 0);

	nnDrs = nnDrsWide;
	aaDrs = aaDrsWide;
    setHook((void*)0x005E4B78, aloadDRSHook );

    //heap corruption
    setHook((void*)0x004D4FE8, adrsHeaderEnd);
    //patchResRects(1920, 1080);
}



