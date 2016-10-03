cmake_minimum_required(VERSION 2.8)

project(FastPD)

if(WIN32)
    if(CMAKE_CL_64)
        set(TARGET_NAME libFastPD-x64)
    else()
        set(TARGET_NAME libFastPD-x86)
    endif()
else()
    set(TARGET_NAME libFastPD)
endif()


include_directories(“${CMAKE_SOURCE_DIR}/src”)

file(GLOB SOURCES ./src/*.cpp)
file(GLOB HEADERS ./src/*.h)

add_library(${TARGET_NAME} SHARED ${SOURCES} ${HEADERS})

set_target_properties( ${TARGET_NAME} PROPERTIES PREFIX "")
