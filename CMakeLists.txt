#Cmake min version
cmake_minimum_required(VERSION 3.5)

# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

#Project's name
project(r-type)

#Set lang to C++ 17
set(CMAKE_CXX_STANDARD 17)

#Set executable at cmake dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

add_definitions( -DBOOST_ALL_NO_LIB )

#Detect and add Boost
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.58.0 COMPONENTS filesystem regex)


add_subdirectory(client)
add_subdirectory(server)
#add_subdirectory(clientUDP)