//
// Created by dev on 10/31/25.
//

#include <windows.h>

int main() {
    // Finding our resource
    PVOID resource = FindResource(NULL, MAKEINTRESOURCE(FAVICON_ICO), RT_DATA);

    DWORD lpflOldProtect = 0;
    DWORD pnameid =  GetCurrentProcessId();

    memAddress = VirtualAlloc(0, );
    BOOL result = VirtualProtect(memAddress);

    return 0;
}