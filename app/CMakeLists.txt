cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_VERBOSE_MAKEFILE on)

set(lib_src_DIR ${CMAKE_SOURCE_DIR}/../libsrc)
set(lib_build_DIR $ENV{HOME}/tmp)
file(MAKE_DIRECTORY ${lib_build_DIR})

set(distribution_DIR ${CMAKE_SOURCE_DIR}/../distribution)

add_library(lib_lua SHARED IMPORTED)
set_target_properties(lib_lua PROPERTIES IMPORTED_LOCATION ${distribution_DIR}/lua/lib/${ANDROID_ABI}/liblua.so)

include_directories(${distribution_DIR}/lua/include)

file(GLOB native_SRC
    "src/main/cpp/native-lib.cpp"
    "src/main/cpp/LuaManager.cpp"
    "src/main/cpp/AntManager.cpp"
)

add_library(native-lib SHARED ${native_SRC})

target_link_libraries(native-lib log lib_lua)
