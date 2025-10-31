# Solution

## Chapter 10-3_01

1. Generate msfvenom calc shellcode and use it instead of the shellcode provided within the loader. Which section does the shellcode end up in?
   a. Force the variable to be compiled in the .text section. This can be done with the
   __declspec attribute in cl or the __attribute__ attribute in mingw.

<br>

---

<br>

## Task 1

- Generating msfvenom shellcode 

```sh
➜  ~ msfvenom -p windows/x64/exec CMD=calc.exe -f C > payload.c
```

<br>

- Within the loader the shellcode can be found in the stack section. 

<br>

- The second memory address is where the VirtualProtect operation occurs, which is the memory region that our shellcode is located in.
  
- The memory regions permissions gets switched from READ and WRITE to READ and EXECUTE permissions, which is more OPSEC friendly than a memory region with READ WRITE and EXECUTE all at once.

> [!info]
> - This is a basic OPSEC improvement but not sufficient evasion
    for enterprise environments.

<br>

---

<br>

## Task 2

- We use the following code snippet in our C program to force the msfvenom shellcode to be loaded to the .text section

- Since I am using mingw I implemented the second code snippet.

```c
// For non mingw
// #pragma section(".text")
// __declspec(allocate(".text"))unsigned char shellcode [] =
//  "..."
```

```c
// mingw
__attribute__((section(".text")))unsigned char shellcode[] =
    "...";
```