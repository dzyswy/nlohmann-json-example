cmake_minimum_required (VERSION 3.16)
project (myproj VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)


set(THIRD_PARTY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty)
set(NLOHMANN_JSON_PATH ${THIRD_PARTY_PATH}/nlohmann-json)
set(NLOHMANN_JSON_INCLUDE_DIRS ${NLOHMANN_JSON_PATH}/include)


include_directories(${NLOHMANN_JSON_INCLUDE_DIRS})

add_executable (myapp main.cpp) 

