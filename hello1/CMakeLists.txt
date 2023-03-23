cmake_minimum_required(VERSION 3.22)
project(hello1)

set(CMAKE_CXX_STANDARD 17)

find_package(XercesC REQUIRED)


include_directories(${XercesC_INCLUDE_DIRS})

add_executable(hello1 main.cpp hello.cxx)

target_link_libraries(${PROJECT_NAME} ${XercesC_LIBRARIES})

