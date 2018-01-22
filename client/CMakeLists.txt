cmake_minimum_required(VERSION 3.5)

#Project's name
project(client)

#Set lang to C++ 17
set(CMAKE_CXX_STANDARD 17)

#Set executable at cmake dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../build)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../build)

INCLUDE_DIRECTORIES(Game/include State/include)

FILE(GLOB CLIENT_GAME_SOURCES Game/include/*.hpp Game/src/*.cpp State/include/*.hpp State/src/*.cpp ../utils/GameEngine/include/*.hpp ../utils/GameEngine/src/*.cpp)
FILE(GLOB CLIENT_GRAPHIC_LIBRARY_SOURCES Lib/include/*.hpp Lib/src/*.cpp)

#Create libUGL.so
add_library(UGL SHARED ${CLIENT_GRAPHIC_LIBRARY_SOURCES})

#Create executable
add_executable(UgandaPilote ${CLIENT_GAME_SOURCES})

target_link_libraries(UgandaPilote UGL)

#Detect and add Lua
find_package(Lua REQUIRED)
if(LUA_FOUND)
    MESSAGE( STATUS "Found Lua ${LUA_VERSION_STRING} in ${LUA_INCLUDE_DIR}")
    include_directories(${LUA_INCLUDE_DIR})
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/build/lua/LuaBridge)
    target_link_libraries(UgandaPilote ${LUA_LIBRARIES})
else()
    MESSAGE(STATUS "LUA not found!")
endif()

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(UgandaPilote ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
    target_link_libraries(UGL ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(UgandaPilote ${Boost_LIBRARIES})
endif()

if (UNIX)
    target_link_libraries(UgandaPilote ${CMAKE_DL_LIBS})
endif()