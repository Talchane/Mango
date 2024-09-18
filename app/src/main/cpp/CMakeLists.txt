# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.22.1)

# Set standards for C and C++
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

# Set the project name based on the name given on the gradle.propertiess
project("${APP_LIB_NAME}")

# Include raylib and raymob as subdirectories
add_subdirectory(${CMAKE_SOURCE_DIR}/deps/raylib)
add_subdirectory(${CMAKE_SOURCE_DIR}/deps/raymob)

# Fetch all C source files recursively, excluding 'deps' source files
file(GLOB_RECURSE C_SOURCES "${CMAKE_SOURCE_DIR}/*.c")

# Fetch all C++ source files recursively, excluding 'deps' source files
file(GLOB_RECURSE CPP_SOURCES "${CMAKE_SOURCE_DIR}/*.cpp")

# Filter out source files inside the 'deps' folder for both C and C++ filesl
list(FILTER C_SOURCES EXCLUDE REGEX "${CMAKE_SOURCE_DIR}/deps/.*")
list(FILTER CPP_SOURCES EXCLUDE REGEX "${CMAKE_SOURCE_DIR}/deps/.*")

# Add headers directory for android_native_app_glue.c
include_directories(${ANDROID_NDK}/sources/android/native_app_glue/)

# Add android_native_app_glue.c to the C source files
list(APPEND C_SOURCES ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c)

# Combine C and C++ source files into a single list
set(SOURCES ${C_SOURCES} ${CPP_SOURCES} ${ETHER_SOURCES})

# Create a shared library with the combined source files (both C and C++)
add_library(${APP_LIB_NAME} SHARED ${SOURCES})

# Define compiler macros for the library
target_compile_definitions(${APP_LIB_NAME} PRIVATE PLATFORM_ANDROID)

# Apply flags depending on the build type
if(CMAKE_BUILD_TYPE MATCHES "Debug")
    target_compile_definitions(${APP_LIB_NAME} PRIVATE _DEBUG DEBUG)
    set(CMAKE_CXX_FLAGS_DEBUG "-g -fno-limit-debug-info")
    set(CMAKE_C_FLAGS_DEBUG "-g -fno-limit-debug-info")
elseif(CMAKE_BUILD_TYPE MATCHES "Release")
    set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
    set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")
endif()

# Include raylib and raymob header files
target_include_directories(${APP_LIB_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/deps/raylib")
target_include_directories(${APP_LIB_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/deps/raymob")

# Include additional headers from the 'Ennemies/Ether' directory
target_include_directories(${APP_LIB_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/Ennemies/Ether")

# Link required libraries to the native application
target_link_libraries(${APP_LIB_NAME} raylib raymoblib)
