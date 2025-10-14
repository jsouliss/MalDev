cmake_minimum_required(VERSION 4.0)
project(MalDev)

set(CMAKE_CXX_STANDARD_14)
set(CMAKE_ASM_STANDARD_REQUIRED ON)

add_subdirectory(local-proc-inj)
add_subdirectory(callback-local-proc-inj)
add_subdirectory(remote-proc-inj)