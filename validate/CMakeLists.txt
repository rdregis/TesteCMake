#in project dir

add_executable(Validate ./source/main.cpp)

include(GNUInstallDirs)
message(STATUS "********************************")
message(STATUS "CMAKE_CURRENT_FILE: ${CMAKE_PARENT_LIST_FILE}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "CMAKE_INSTALL_BINDIR: ${CMAKE_INSTALL_BINDIR}")
message(STATUS "CMAKE_INSTALL_LIBDIR: ${CMAKE_INSTALL_LIBDIR}")

message(STATUS "JSONCPP_INCLUDE_DIR: ${JSONCPP_INCLUDE_DIR}")

target_include_directories(Validate PUBLIC ${JSONCPP_INCLUDE_DIR})
target_link_libraries(Validate PRIVATE ${JSONCPP_LIB_DIR})
