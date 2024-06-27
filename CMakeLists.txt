#in most outside dir
cmake_minimum_required(VERSION 3.17)

project(JsonValidate VERSION 1.0.0 LANGUAGES C CXX)
add_subdirectory(validate)

include(GNUInstallDirs)
message(STATUS "********************************")
message(STATUS "CMAKE_CURRENT_FILE: ${CMAKE_PARENT_LIST_FILE}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "CMAKE_INSTALL_BINDIR: ${CMAKE_INSTALL_BINDIR}")
message(STATUS "CMAKE_INSTALL_LIBDIR: ${CMAKE_INSTALL_LIBDIR}")

find_path(JSONCPP_INCLUDE_DIR json 
    HINTS /usr/include/jsoncpp REQUIRED)  
find_library(JSONCPP_LIB_DIR jsoncpp REQUIRED)

message(STATUS "JSONCPP_INCLUDE_DIR: ${JSONCPP_INCLUDE_DIR}")
message(STATUS "JSONCPP_LIB_DIR: ${JSONCPP_LIB_DIR}")

#message(STATUS "JSONCPPX_INCLUDE_DIR: ${JSONCPPX_INCLUDE_DIR}")
#     HINTS
#     ${CMAKE_CURRENT_SOURCE_DIR}/include
#     ${CMAKE_CURRENT_SOURCE_DIR}/jsoncpp/include
#     ${CMAKE_CURRENT_SOURCE_DIR}/jsoncpp/dist/json
#     ${CMAKE_CURRENT_SOURCE_DIR}/jsoncpp/dist
#     ${CMAKE_CURRENT_SOURCE_DIR}/jsoncpp
#     ${CMAKE_CURRENT_SOURCE_DIR}
#     PATH_SUFFIXES jsoncpp
# )
# add_library(JsonCpp SHARED IMPORTED GLOBAL)
# set_target_properties(JsonCpp PROPERTIES
#     IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/lib/libjsoncpp.so"
#     INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include"

#add_executable(JsonValidate main.cpp)

#find_package(JsonCpp REQUIRED)