project(SshUpdater)
cmake_minimum_required(VERSION 3.9)

aux_source_directory(. SRC_LIST)
aux_source_directory(Ssh  SRC_LIST)
aux_source_directory(rapidjson SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)

#  sudo apt-get install libssh2-1-dev
find_library(SSH2_LIBRARY ssh2 REQUIRED)

link_directories(${SSH2_LIBRARY_DIR})
target_link_libraries(${PROJECT_NAME} ${SSH2_LIBRARY})



