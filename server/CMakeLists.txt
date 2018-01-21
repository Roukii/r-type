#Cmake min version
cmake_minimum_required(VERSION 3.5)

# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

#Project's name
project(r-type_server)

#Set lang to C++ 98
set(CMAKE_CXX_STANDARD 17)

#Set executable at cmake dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

#Add include
include_directories(include)

#Add sources
file(GLOB SERVER_SOURCE_FILES src/*.cpp include/*.h include/*.hpp)
#set(SERVER_SOURCE_FILES src/Rtype.cpp include/ServerUdp.hpp src/ServerUdp.cpp src/Network.cpp include/Network.h src/ServerCore.cpp include/ServerCore.hpp)

#Create executable
add_executable(Server ${SERVER_SOURCE_FILES})

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(Server ${Boost_LIBRARIES})
endif()

if (UNIX)
    target_link_libraries(ClientTest ${CMAKE_THREAD_LIBS_INIT})
endif()