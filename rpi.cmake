INCLUDE(CMakeForceCompiler)

# this one is important
SET(CMAKE_SYSTEM_NAME Linux)
#this one not so much
SET(CMAKE_SYSTEM_VERSION 1)

# specify the cross compiler
CMAKE_FORCE_C_COMPILER( arm-none-eabi-gcc GNU )
CMAKE_FORCE_CXX_COMPILER( arm-none-eabi-g++ GNU )

# where is the target environment 
#SET(CMAKE_FIND_ROOT_PATH  /opt/eldk-2007-01-19/ppc_74xx /home/alex/eldk-ppc74xx-inst)

# Show verbose build, highly useful
set( CMAKE_VERBOSE_MAKEFILE OFF )

# Standard flags	
set( CMAKE_C_FLAGS 		"-Wall -O2 -nostdlib -nostartfiles -ffreestanding" )
set( CMAKE_C_FLAGS_DEBUG	"${CMAKE_CXX_FLAGS}" )
set( CMAKE_C_FLAGS_RELEASE	"${CMAKE_CXX_FLAGS}" )

# search for programs in the build host directories
SET( CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER )

# for libraries and headers in the target directories
SET( CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY )
SET( CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY )
