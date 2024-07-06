#cmake_minimum_required(VERSION 3.1)
#project(MyDimServer)
#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(SOURCES "src/main.cpp")

#add_executable(MyDimServerExec ${SOURCES})

#target_include_directories(MyDimServerExec PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

#target_link_libraries(MyDimServerExec PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/dim/linux/libdim.a)



cmake_minimum_required(VERSION 3.1)
#set(CMAKE_CXX_STANDARD 17)
project(FREDServer2)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ./lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ./lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

#file(GLOB SOURCES "src/main.cpp")
set(FILES src/main.cpp)
add_executable(FREDServer2 ${FILES})

target_include_directories(FREDServer2 PRIVATE dim/dim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -gdwarf-4 -D_GLIBCXX_USE_CXX11_ABI=0")

target_link_libraries(FREDServer2 ${CMAKE_SOURCE_DIR}/dim/linux/libdim.a pthread stdc++)
