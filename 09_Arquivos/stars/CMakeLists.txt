cmake_minimum_required (VERSION 4.0.0)

project(stars)

file(GLOB SOURCE_FILES main.c)
file(GLOB INCLUDE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_executable(stars ${SOURCE_FILES} ${INCLUDE_FILES})

SET(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")

if(APPLE)
    target_compile_definitions(stars PRIVATE GL_SILENCE_DEPRECATION)
endif()

set(INCLUDE_DIRS include)

include_directories(${INCLUDE_DIRS})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

target_link_libraries(stars PRIVATE
    OpenGL::GL
    GLUT::GLUT
    m
)

