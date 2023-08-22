cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(chat VERSION 1.0)

# add the executable
add_executable(chat main.cpp)
target_sources(chat PRIVATE chat.cpp sha1.cpp sql.cpp)
target_include_directories(chat PUBLIC ./)
