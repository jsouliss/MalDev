set(CMAKE_SYSTEM_NAME Windows)

###########################################

# 32-bit Target Environment
# set(CMAKE_SYSTEM_PROCESSOR i686)
# set(CMAKE_C_COMPILER /opt/homebrew/bin/i686-w64-mingw32-gcc)
# set(CMAKE_CXX_COMPILER /opt/homebrew/bin/i686-w64-mingw32-g++)
# set(CMAKE_RC_COMPILER /opt/homebrew/bin/i686-w64-mingw32-windres)
# set(CMAKE_RANLIB /opt/homebrew/bin/i686-w64-mingw32-ranlib)

# Target environment
# set(CMAKE_FIND_ROOT_PATH /opt/homebrew/opt/mingw-w64)

###########################################

# 64-bit Target Environment
set(CMAKE_SYSTEM_PROCESSOR x86_64)
set(CMAKE_C_COMPILER /opt/homebrew/bin/x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER /opt/homebrew/bin/x86_64-w64-mingw32-g++)
set(CMAKE_RC_COMPILER /opt/homebrew/bin/x86_64-w64-mingw32-windres)
set(CMAKE_RANLIB /opt/homebrew/bin/x86_64-w64-mingw32-ranlib)

# Target environment
set(CMAKE_FIND_ROOT_PATH /opt/homebrew/opt/mingw-w64)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

add_compile_definitions(UNICODE _UNICODE)

# Adjust the default behavior of FIND_XXX() commands
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)