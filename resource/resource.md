# For Linux cross compilation:

## .rc to .res
x86_64-w64-mingw32-windres resources.rc -O res -o resources.res

## .res to .o

```
x86_64-w64-mingw32-windres resources.res -O coff -o resources.o
```

## Link with your code

```
x86_64-w64-mingw32-gcc main.c resources.o -o resources_loader.exe
```

---

# Windows compiling resource:

- Use resource compiler binary to compile the .rc file into a .res file type.

```
rc resources.rc
```

- Use cvtres to convert the .res file into an object file.

```
cvtres /MACHINE:x64 /OUT:resources.o resources.res
```

- Use a native compiler to link the loader code with the resources object file into a PE file.

```   
cl.exe /nologo /Ox /MT /W0 /GS- /DNDEBUG /Tcresources_loader.cpp /link /OUT:resources_loader.exe /SUBSYSTEM:CONSOLE /MACHINE:x64 resources.o
```