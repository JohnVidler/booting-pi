cmake_minimum_required( VERSION 2.8 )
include( rpi.cmake )
enable_language( ASM-ATT OPTIONAL )
project( BootingPI )

# Linker flags - prevent CMake from being stupid and adding -rdynamic to everything!
set( CMAKE_SHARED_LIBRARY_LINK_C_FLAGS ) 

# Standard flags	
set( CMAKE_C_FLAGS 		"-Wall -O2 -nostdlib -nostartfiles -ffreestanding" )
set( CMAKE_C_FLAGS_DEBUG	"${CMAKE_CXX_FLAGS}" )
set( CMAKE_C_FLAGS_RELEASE	"${CMAKE_CXX_FLAGS}" )

add_subdirectory( hardware )

add_executable( bootloader booting_pi.c )
target_link_libraries( bootloader hardware )
