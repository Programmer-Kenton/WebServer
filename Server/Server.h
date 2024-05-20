/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 24-5-20 下午6:51
 * @Author Kenton
 */
#ifndef WEBSERVER_SERVER_H
#define WEBSERVER_SERVER_H

#include<unistd.h>
#include<pthread.h>
#include<sys/resource.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../Socket/Socket.h"
#include"../Signal/Signals.h"
#include"../Client/Client.h"
#include"../Server/Server.h"

//初始化服务器
int initServer(short port);
//运行服务器
int runServer(const char* home);
//终结化服务器
void deinitServer(void);


#endif //WEBSERVER_SERVER_H
