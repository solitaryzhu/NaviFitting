cmake_minimum_required(VERSION 2.8)
project(navi_fitting)

set(CMAKE_CXX_FLAGS_DEBUG "${CXXFLAGS} -O0 -g -Wall -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "${CXXFLAGS} -02 -Wall")

include_directories("${CMAKE_SOURCE_DIR}/trunk/inc/")

file(GLOB_RECURSE INCS "${CMAKE_CURRENT_SOURCE_DIR}/trunk/inc/*.h")
file(GLOB_RECURSE SRCS "${CMAKE_CURRENT_SOURCE_DIR}/trunk/src/*.cpp")

add_executable("${PROJECT_NAME}" "${SRCS}" "${INCS}")

find_package(Boost 1.59 REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()

target_link_libraries(
    "${PROJECT_NAME}"
    dl
    pthread)
