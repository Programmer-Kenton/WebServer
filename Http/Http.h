/**
 * @Description Http模块 头文件
 * @Version 1.0.0
 * @Date 2024/5/20 14:54
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */
#ifndef WEBSERVER_HTTP_H
#define WEBSERVER_HTTP_H

#include<limits.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/syscall.h>//
#include<stdio.h>
#include<string.h>
#include<time.h>


//用来表示解析等到的收据
typedef struct httpRequest{
    char method[32];//请求方法
    char path[PATH_MAX + 1];//资源路径
    char protocol[32];//协议版本
    char connection[32];//连接状态
} HTTP_REQUEST;

//http请求的解析
int parseRequest(const char* req,HTTP_REQUEST* hreq);

//构造响应头时需要的数据
typedef struct httpRespond{
    char protocol[32];//协议版本
    int status;//状态码
    char desc[128];//状态描述
    char type[64];//类型
    off_t length;//长度
    char connection[32];//连接状态
} HTTP_RESPOND;

//http响应的构造
int constructHead(const HTTP_RESPOND* hres,char* head);


#endif //WEBSERVER_HTTP_H
