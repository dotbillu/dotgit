cmake_minimum_required(VERSION 4.3)

project(dotgit LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenSSL REQUIRED)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)

add_executable(dot ${SOURCES})

target_link_libraries(dot PRIVATE OpenSSL::Crypto)
