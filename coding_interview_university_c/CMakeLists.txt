cmake_minimum_required(VERSION 3.11)
project(coding_interview C CXX)

add_definitions(-Wall -Werror)
include_directories(${PROJECT_SOURCE_DIR}/src/)
file(GLOB CODING_INTERVIEW_SRC ${PROJECT_SOURCE_DIR}/src/*.c)

add_executable(ci ${CODING_INTERVIEW_SRC})

add_subdirectory(${PROJECT_SOURCE_DIR}/external/doctest)
file(GLOB CODING_INTERVIEW_TESTS ${PROJECT_SOURCE_DIR}/src/*_test.cpp)
add_executable(tests ${CODING_INTERVIEW_TESTS})
target_link_libraries(tests doctest)
