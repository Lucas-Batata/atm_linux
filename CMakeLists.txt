cmake_minimum_required(VERSION 2.8)
project(atm)
include_directories(${PROJECT_SOURCE_DIR}/include)
#set(SOURCES src/cubo.cpp src/main.cpp)
file(GLOB SOURCES "src/*cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

