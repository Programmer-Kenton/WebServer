/**
 * @Description 线程模块 头文件
 * @Version 1.0.0
 * @Date 2024/5/20 14:54
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */
#ifndef WEBSERVER_CLIENT_H
#define WEBSERVER_CLIENT_H

//线程模块实现
#include<unistd.h>
#include<sys/syscall.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../Http/Http.h"
#include"../Socket/Socket.h"
#include"../Resource/Resource.h"
#include"../Client/Client.h"


//线程过程函数的参数
typedef struct clientArgs{
    const char* home;//资源在本地的存储路径
    int conn;//通信套接字
} CA;

//线程过程函数,负责完成和客户端的通信
void* client(void* arg);


#endif //WEBSERVER_CLIENT_H
