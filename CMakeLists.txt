cmake_minimum_required(VERSION 3.10.0)
project(projects_1 VERSION 0.1.0 LANGUAGES CXX)  

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MINGW)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wa,-mbig-obj")
endif()

include_directories(
    ${CMAKE_SOURCE_DIR}/inc  
    ${CMAKE_SOURCE_DIR}/src  
)

file(GLOB SOURCES
    "src/*.cpp"
    "main.cpp"
)

add_executable(projects_1 ${SOURCES})

if(WIN32)
    target_link_libraries(projects_1)
endif()
