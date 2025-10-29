# This must be first - before any project() or enable_language()
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

# Specify we're cross-compiling
set(CMAKE_CROSSCOMPILING TRUE)

# Compilers - use full paths
set(CMAKE_C_COMPILER /opt/homebrew/bin/x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER /opt/homebrew/bin/x86_64-w64-mingw32-g++)
set(CMAKE_RC_COMPILER /opt/homebrew/bin/x86_64-w64-mingw32-windres)
set(CMAKE_RANLIB /opt/homebrew/bin/x86_64-w64-mingw32-ranlib)

# CRITICAL: Skip compiler checks that add -arch flags
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)
set(CMAKE_C_ABI_COMPILED TRUE)
set(CMAKE_CXX_ABI_COMPILED TRUE)

# Remove any macOS-specific compiler flags
set(CMAKE_C_OSX_DEPLOYMENT_TARGET_FLAG "")
set(CMAKE_CXX_OSX_DEPLOYMENT_TARGET_FLAG "")
set(CMAKE_C_SYSROOT_FLAG "")
set(CMAKE_CXX_SYSROOT_FLAG "")

# Target environment
set(CMAKE_FIND_ROOT_PATH /opt/homebrew/opt/mingw-w64)

# Linker flags for static linking
set(CMAKE_EXE_LINKER_FLAGS_INIT "-static-libgcc -static-libstdc++ -static")
set(CMAKE_SHARED_LINKER_FLAGS_INIT "-static-libgcc -static-libstdc++")

# Compile definitions
add_compile_definitions(UNICODE _UNICODE)

# Adjust the default behavior of FIND_XXX() commands
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)