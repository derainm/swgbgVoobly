
#include "language.h"

//005E40A2 | .BF 7C9D6900    MOV EDI, battlegr.00699D7C;  ASCII "language_x1.dll"
//005E40A7 | . 33C0           XOR EAX, EAX

char lang[255] = "..\\Voobly Mods\\SWBGCC\\Data Mods\\Expanding Fronts 1.4.1\\language_x2.dll";

DWORD _005E40A9 = 0x05E40A9;
__declspec(naked) void overWriteLangx11() //004D4FE8
{
    __asm
    {
        MOV EDI , OFFSET lang
        XOR EAX, EAX
        JMP _005E40A9 
    }
}

void languageOverwrite1()
{
    //005E40A2  |. BF 7C9D6900    MOV EDI,battlegr.00699D7C                              ;  ASCII "language_x1.dll"
    setHook((void*)0x05E40A2, overWriteLangx11);
}