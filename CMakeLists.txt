#Cmake min version
cmake_minimum_required(VERSION 3.5)

#Project's name
project(r-type)

#Set lang to C++ 98
set(CMAKE_CXX_STANDARD 17)

#Set executable at cmake dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

#Add sources
set(SOURCE_FILES main.cpp)

#Create executable
add_executable(UgandaPilote ${SOURCE_FILES})