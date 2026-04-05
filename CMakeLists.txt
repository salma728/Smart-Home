cmake_minimum_required(VERSION 3.10)
project(SmartHome CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect all .cpp files
file(GLOB_RECURSE SOURCES
    "main.cpp"
    "devices/*.cpp"
    "state/*.cpp"
    "factory/*.cpp"
    "composite/*.cpp"
    "observer/*.cpp"
    "command/*.cpp"
    "strategy/*.cpp"
    "facade/*.cpp"
)

add_executable(smarthome ${SOURCES})

target_include_directories(smarthome PRIVATE
    devices
    state
    factory
    composite
    observer
    command
    strategy
    facade
)
