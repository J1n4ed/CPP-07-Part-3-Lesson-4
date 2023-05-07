cmake_minimum_required(VERSION 3.22.0)
project(Catch2-HW1)
add_executable(Catch2_Main src/main.cpp src/struct.cpp)

add_subdirectory(../Catch2 Catch2-bujild)
#find_package(Catch2 3 REQUIRED)
add_executable(Catch2_Main_Test src/test.cpp src/struct.cpp)
target_link_libraries(Catch2_Main_Test PRIVATE Catch2::Catch2WithMain)