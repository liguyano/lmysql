cmake_minimum_required(VERSION 3.24)
project(netWork)

set(CMAKE_CXX_STANDARD 17)
link_directories("/usr/lib/mysql")

add_executable(netWork main.cpp Mysql_connecter.cpp Mysql_connecter.h Tcp_handle.cpp Tcp_handle.h Thread.cpp Thread.h)
target_link_libraries(netWork mysqlclient)