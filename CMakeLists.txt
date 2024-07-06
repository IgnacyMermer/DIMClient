cmake_minimum_required(VERSION 3.10)

# Nazwa projektu
project(MyProject)

# Dodajemy główne pliki źródłowe
add_executable(MyProject src/main.cpp)

# Dodajemy katalogi z nagłówkami z zewnętrznego projektu
include_directories(${CMAKE_SOURCE_DIR}/dim/dim)

# Linkujemy skompilowaną bibliotekę
target_link_libraries(MyProject ${CMAKE_SOURCE_DIR}/dim/linux/libdim.a pthread)

# Możesz także zdefiniować ścieżki jako zmienne, aby ułatwić zarządzanie
#set(DIM_LIB_DIR ${CMAKE_SOURCE_DIR}/dim)
#set(DIM_INCLUDE_DIR ${DIM_LIB_DIR}/linux)

#include_directories(${DIM_INCLUDE_DIR})
#target_link_libraries(MyProject ${DIM_LIB_DIR}/libdim.a)
