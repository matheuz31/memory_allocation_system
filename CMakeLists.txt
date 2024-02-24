cmake_minimum_required(VERSION 3.10)

project(memory_allocation_system)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

# Adicione os arquivos fonte
file(GLOB SOURCES "src/*.cpp")

# Crie o executável a partir dos fontes
add_executable(memory_allocation_system ${SOURCES})