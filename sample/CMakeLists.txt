cmake_minimum_required(VERSION 2.8)
set(CMAKE_MODULE_PATH /usr/share/cmake-2.8/Modules/)
include(FRCDeploy)

project(MyRobot)
find_package(WPILib)
include_directories(${WPILib_INCLUDE_DIRS})

file(GLOB SOURCE_CODE *.cpp)

add_executable(out ${SOURCE_CODE})
target_link_libraries(out ${WPILib_LIBRARY})

add_make_deploy(out 10.xx.yy.2) # where your team number is xxyy
