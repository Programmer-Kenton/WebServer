/**
 * @Description Socket通信模块 头文件
 * @Version 1.0.0
 * @Date 2024/5/20 14:54
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */
#ifndef WEBSERVER_SOCKET_H
#define WEBSERVER_SOCKET_H

#include "unistd.h"
#include "fcntl.h"
#include "sys/syscall.h"
#include "sys/socket.h"
#include "sys/types.h"
#include "arpa/inet.h"
#include "stdio.h"
#include "stdlib.h"
#include "cstring"
#include "iostream"


//初始化套接字
int initSocket(short port);
//接受客户端的连接请求
int acceptClient(void);
//接受http请求
char* recvRequest(int conn);
//发送http响应头
int sendHead(int conn,const char* head);
//发送http响应体
int sendBody(int conn,const char* path);
//终结化套接字
void deinitSocket(void);



#endif //WEBSERVER_SOCKET_H
