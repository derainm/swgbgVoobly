#pragma once
#include <Windows.h>

typedef uintptr_t addr;

#define WRAPPER __declspec(naked)
#define DEPRECATED __declspec(deprecated)
#define EAXJMP(a) { _asm mov eax, a _asm jmp eax }
#define VARJMP(a) { _asm jmp a }
#define WRAPARG(a) UNREFERENCED_PARAMETER(a)

#define RET(n)	__asm push	n __asm retn
#define ASM(name) void __declspec(naked) name(void)
 

#define NOVMT __declspec(novtable)
#define SETVMT(a) *((DWORD_PTR *)this) = (DWORD_PTR)a
#define PTRFROMCALL(addr) (uint32_t)(*(uint32_t*)((uint32_t)addr+1) + (uint32_t)addr + 5)
#define INTERCEPT(saved, func, a) \
do { \
	saved = PTRFROMCALL(a); \
	InjectHook(a, func); \
} while (0)
#define RET(n)	__asm push	n __asm retn
#define ASM(name) void __declspec(naked) name(void)

#pragma warning(disable:4731) // -- suppress C4731:"frame pointer register 'ebp' modified by inline assembly code"

#define XCALL(uAddr)			\
	__asm { mov esp, ebp	}	\
	__asm { pop ebp			}	\
	__asm { mov eax, uAddr	}	\
	__asm { jmp eax			}

#define FIELD(type, var, offset) *(type *)((unsigned char *)var + offset)

template<typename T> inline void Patch(DWORD address, T value)
{
	DWORD dwProtect[2];
	VirtualProtect((void *)address, sizeof(T), PAGE_EXECUTE_READWRITE, &dwProtect[0]);
	*(T *)address = value;
	VirtualProtect((void *)address, sizeof(T), dwProtect[0], &dwProtect[1]);
}

inline void PatchBytes(DWORD address, void *value, size_t nCount)
{
	DWORD dwProtect[2];
	VirtualProtect((void *)address, nCount, PAGE_EXECUTE_READWRITE, &dwProtect[0]);
	memcpy((void *)address, value, nCount);
	VirtualProtect((void *)address, nCount, dwProtect[0], &dwProtect[1]);
}

inline void ReadBytes(DWORD address, void *out, size_t nCount)
{
	DWORD dwProtect[2];
	VirtualProtect((void *)address, nCount, PAGE_EXECUTE_READWRITE, &dwProtect[0]);
	memcpy(out, (void *)address, nCount);
	VirtualProtect((void *)address, nCount, dwProtect[0], &dwProtect[1]);
}

inline void Nop(DWORD address, size_t nCount = 1)
{
	DWORD dwProtect[2];
	VirtualProtect((void *)address, nCount, PAGE_EXECUTE_READWRITE, &dwProtect[0]);
	memset((void *)address, 0x90, nCount);
	VirtualProtect((void *)address, nCount, dwProtect[0], &dwProtect[1]);
}

inline void NopTo(DWORD address, DWORD to)
{
	Nop(address, to - address);
}

enum
{
	PATCH_CALL,
	PATCH_JUMP,
	PATCH_NOTHING,
	HOOK_SIZE = 5,
};

template<typename T> inline void InjectHook(DWORD address, T hook, int nType = PATCH_NOTHING)
{
	DWORD dwProtect[2];
	switch (nType)
	{
	case PATCH_JUMP:
		VirtualProtect((void *)address, HOOK_SIZE, PAGE_EXECUTE_READWRITE, &dwProtect[0]);
		*(BYTE *)address = 0xE9;
		break;
	case PATCH_CALL:
		VirtualProtect((void *)address, HOOK_SIZE, PAGE_EXECUTE_READWRITE, &dwProtect[0]);
		*(BYTE *)address = 0xE8;
		break;
	default:
		VirtualProtect((void *)((DWORD)address + 1), HOOK_SIZE - 1, PAGE_EXECUTE_READWRITE, &dwProtect[0]);
		break;
	}
	DWORD dwHook;
	// DWORD PTR for casting 8 byte function pointers down to 4
	_asm
	{
		mov	eax, DWORD PTR hook
		mov DWORD PTR dwHook, eax
	}

	*(ptrdiff_t *)((DWORD)address + 1) = (DWORD)dwHook - (DWORD)address - HOOK_SIZE;

	if (nType == PATCH_NOTHING)
		VirtualProtect((void *)((DWORD)address + 1), HOOK_SIZE - 1, dwProtect[0], &dwProtect[1]);
	else
		VirtualProtect((void *)address, HOOK_SIZE, dwProtect[0], &dwProtect[1]);
}

inline void PatchJump(DWORD address, DWORD to)
{
	InjectHook(address, to, PATCH_JUMP);
}

inline void ExtractCall(void *dst, addr a)
{
	*(addr *)dst = (addr)(*(addr *)(a + 1) + a + 5);
}

template<typename T> inline void InterceptCall(void *dst, T func, addr a)
{
	ExtractCall(dst, a);
	InjectHook(a, func);
}

template<typename T> inline void InterceptVmethod(void *dst, T func, addr a)
{
	*(addr *)dst = *(addr *)a;
	Patch(a, func);
}

inline bool Hook(void* toHook, void* ourFunct, int len) {
	if (len < 5) {
		return false;
	}

	DWORD curProtection;
	VirtualProtect(toHook, len, PAGE_EXECUTE_READWRITE, &curProtection);

	memset(toHook, 0x90, len);

	DWORD relativeAddress = ((DWORD)ourFunct - (DWORD)toHook) - 5;

	*(BYTE*)toHook = 0xE9;
	*(DWORD*)((DWORD)toHook + 1) = relativeAddress;

	DWORD temp;
	VirtualProtect(toHook, len, curProtection, &temp);

	return true;
}
inline void __cdecl setHook(void* addr, void* newAddr)
{

	unsigned long c;
	unsigned char j = 0xE9;
	WriteProcessMemory(GetCurrentProcess(), addr, &j, 1, (SIZE_T*)&c);
	char* r = (char*)newAddr - (char*)addr + (char*)-5;
	WriteProcessMemory(GetCurrentProcess(), (char*)addr + 1, &r, 4, (SIZE_T*)&c);

}
//long Je
inline void __cdecl setHookJE(void* addr, void* newAddr)
{
	unsigned long c;
	unsigned char j = 0x0F;
	unsigned char jg = 0x84;
	WriteProcessMemory(GetCurrentProcess(), addr, &j, 1, (SIZE_T*)&c);
	WriteProcessMemory(GetCurrentProcess(), (char*)addr + 1, &jg, 1, (SIZE_T*)&c);
	char* r = (char*)newAddr - (char*)addr + (char*)-5 - 1;
	WriteProcessMemory(GetCurrentProcess(), (char*)addr + 2, &r, 4, (SIZE_T*)&c);

}
inline void __cdecl setHookJA(void* addr, void* newAddr)
{
	unsigned long c;
	unsigned char j = 0x0F;
	unsigned char jg = 0x87;
	WriteProcessMemory(GetCurrentProcess(), addr, &j, 1, (SIZE_T*)&c);
	WriteProcessMemory(GetCurrentProcess(), (char*)addr + 1, &jg, 1, (SIZE_T*)&c);
	char* r = (char*)newAddr - (char*)addr + (char*)-5 - 1;
	WriteProcessMemory(GetCurrentProcess(), (char*)addr + 2, &r, 4, (SIZE_T*)&c);

}
inline void __cdecl setHookCall(void* addr, void* newAddr)
{
	unsigned long c;
	unsigned char j = 0xE8;
	WriteProcessMemory(GetCurrentProcess(), addr, &j, 1, (SIZE_T*)&c);
	char* r = (char*)newAddr - (char*)addr + (char*)-5;
	WriteProcessMemory(GetCurrentProcess(), (char*)addr + 1, &r, 4, (SIZE_T*)&c);

}
inline void __cdecl writeByte(DWORD addr, BYTE val)
{
	WriteProcessMemory(GetCurrentProcess(), (void*)addr, &val, 1, 0);
}
inline void __cdecl writeData(DWORD addr, void* data, int len)
{
	WriteProcessMemory(GetCurrentProcess(), (void*)addr, data, len, 0);
}

inline void __cdecl writeDwordF(DWORD addr, DWORD val)
{
	//WriteProcessMemory(GetCurrentProcess(), (void*)(addr + 0x400000 + 1), &val, 3, 0);
	WriteProcessMemory(GetCurrentProcess(), (void*)(addr + 0x400000), &val, 4, NULL);
}
inline void __cdecl writeDwordF1(DWORD addr, DWORD val)
{
	WriteProcessMemory(GetCurrentProcess(), (void*)(addr + 0x400000), &val, 3, 0);
}
inline void __cdecl writeDwordF3(DWORD addr, DWORD val)
{
	WriteProcessMemory(GetCurrentProcess(), (void*)(addr + 0x400000+1), &val, 3, 0);
}
inline void __cdecl writeDword(DWORD addr, DWORD val)
{
	WriteProcessMemory(GetCurrentProcess(), (void*)addr, &val, 4, 0);
}
template<typename AT, typename HT> inline void
InjectHook(AT uintptr_tess, HT hook, unsigned int nType = PATCH_NOTHING)
{
	DWORD		dwProtect[2];
	switch (nType)
	{
	case PATCH_JUMP:
		VirtualProtect((void*)uintptr_tess, 5, PAGE_EXECUTE_READWRITE, &dwProtect[0]);
		*(BYTE*)uintptr_tess = 0xE9;
		break;
	case PATCH_CALL:
		VirtualProtect((void*)uintptr_tess, 5, PAGE_EXECUTE_READWRITE, &dwProtect[0]);
		*(BYTE*)uintptr_tess = 0xE8;
		break;
	default:
		VirtualProtect((void*)((DWORD)uintptr_tess + 1), 4, PAGE_EXECUTE_READWRITE, &dwProtect[0]);
		break;
	}
	DWORD		dwHook;
	_asm
	{
		mov		eax, hook
		mov		dwHook, eax
	}

	*(ptrdiff_t*)((DWORD)uintptr_tess + 1) = (DWORD)dwHook - (DWORD)uintptr_tess - 5;
	if (nType == PATCH_NOTHING)
		VirtualProtect((void*)((DWORD)uintptr_tess + 1), 4, dwProtect[0], &dwProtect[1]);
	else
		VirtualProtect((void*)uintptr_tess, 5, dwProtect[0], &dwProtect[1]);
}
