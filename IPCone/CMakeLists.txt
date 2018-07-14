cmake_minimum_required(VERSION 3.8)
project(Server)

set(CMAKE_CXX_STANDARD 11)


set(SHARED_SOURCE_FILES protocol.h Receiver.cpp Receiver.h MessageBuilder.cpp MessageBuilder.h Serilizer.cpp Serilizer.h Sender.cpp Sender.h Receiver.cpp Receiver.h Message.h Buffer.h Deserilizer.cpp Deserilizer.h OperatorResolver.cpp OperatorResolver.h Examples/ExampleFunctions.cpp Examples/ExampleFunctions.h Examples/Movie.cpp Examples/Movie.h Examples/Cinema.cpp Examples/Cinema.h ObjectPool.cpp ObjectPool.h)

set(SERVER_SOURCE_FILES server.cpp)
add_executable(Server ${SERVER_SOURCE_FILES} ${SHARED_SOURCE_FILES})


set(CLIENT_SOURCE_FILES client.cpp)
add_executable(Client ${CLIENT_SOURCE_FILES} ${SHARED_SOURCE_FILES})