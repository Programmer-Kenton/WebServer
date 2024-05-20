cmake_minimum_required(VERSION 3.27)
project(WebServer)

set(CMAKE_CXX_STANDARD 17)

add_executable(WebServer main.cpp
        Http/Http.cpp
        Http/Http.h
        Socket/Socket.cpp
        Socket/Socket.h
        Resource/Resource.cpp
        Resource/Resource.h
        Resource/mime.h
        Signal/Signals.cpp
        Signal/Signals.h
        Client/Client.cpp
        Client/Client.h
        Server/Server.cpp
        Server/Server.h
)
