
Install
sudo apt-get install libjsoncpp-dev

Cmake file 
find_path(JSONCPP_INCLUDE_DIR json 
    HINTS /usr/include/jsoncpp REQUIRED) 
find_library(JSONCPP_LIB_DIR jsoncpp REQUIRED)
target_include_directories(<target> PUBLIC ${JSONCPP_INCLUDE_DIR})
target_link_libraries(<target> PRIVATE ${JSONCPP_LIB_DIR})

