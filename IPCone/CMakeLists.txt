cmake_minimum_required(VERSION 3.8)
project(Server)

set(CMAKE_CXX_STANDARD 11)


set(SHARED_SOURCE_FILES protocol.h MessageBuilder.cpp MessageBuilder.h Serilizer.cpp Serilizer.h)

set(SERVER_SOURCE_FILES server.cpp)
add_executable(Server ${SERVER_SOURCE_FILES} ${SHARED_SOURCE_FILES})


set(CLIENT_SOURCE_FILES client.cpp)
add_executable(Client ${CLIENT_SOURCE_FILES} ${SHARED_SOURCE_FILES})