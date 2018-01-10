#Cmake min version
cmake_minimum_required(VERSION 3.5)

# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

#Project's name
project(r-type)

#Set lang to C++ 98
set(CMAKE_CXX_STANDARD 17)

#Set executable at cmake dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

#Add sources
set(SOURCE_FILES main.cpp utils client/State/src/Core.cpp client/State/src/GameScreen.cpp client/State/src/MenuScreen.cpp client/State/src/OptionsScreen.cpp client/State/src/SplashScreen.cpp)

#Create executable
add_executable(UgandaPilote ${SOURCE_FILES})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(UgandaPilote ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

#Detect and add Boost
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.58.0 COMPONENTS filesystem regex)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(UgandaPilote ${Boost_LIBRARIES})
endif()