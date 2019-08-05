cmake_minimum_required(VERSION 2.8)
project(Server CXX)

find_package(Protobuf REQUIRED)

set(GRPC_INSTALL_DIR $ENV{GRPC_INSTALL_DIR})
set(LIBS -pthread /usr/local/lib/libprotobuf.a  -lgrpc++ -lgrpc -lssl -lcrypto)

include_directories(${GRPC_INSTALL_DIR}/include)
include_directories(${Boost_INCLUDE_DIRS})
include_directories(include)


set(SOURCES
    main.cpp
    authservice.cpp
    login.grpc.pb.cc
    login.pb.cc
)
set(HEADERS
    authservice.h
    login.grpc.pb.h
    login.pb.h
 )

add_executable(Server ${SOURCES} ${HEADERS})
target_link_libraries(Server ${LIBS})
