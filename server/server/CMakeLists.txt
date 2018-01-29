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
include_directories(include ../utils/ ../utils/GameEngine ../utils/Protocol Game/include State/include Lib/include ../utils/GameEngine/include Network/include)

#Add sources
file(GLOB SERVER_SOURCE_FILES src/*.cpp include/*.h include/*.hpp ../utils/*.h ../utils/Protocol/*.hpp Game/include/*.hpp Game/src/*.cpp State/include/*.hpp State/src/*.cpp Network/include/*.hpp ../utils/GameEngine/include/*.hpp ../utils/GameEngine/src/*.cpp ../utils/RTypeException.hpp)
#set(SERVER_SOURCE_FILES src/Rtype.cpp include/ServerUdp.hpp src/ServerUdp.cpp src/Network.cpp include/Network.h src/ServerCore.cpp include/ServerCore.hpp)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)

#Create executable
add_executable(Server ${SERVER_SOURCE_FILES})

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(Server ${Boost_LIBRARIES})
endif()

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Server ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

if (UNIX)
    target_link_libraries(Server ${CMAKE_DL_LIBS})
    target_link_libraries(Server -lpthread)
endif()