/**
 * @Description 资源模块 头文件
 * @Version 1.0.0
 * @Date 2024/5/20 14:54
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */
#ifndef WEBSERVER_RESOURCE_H
#define WEBSERVER_RESOURCE_H

#include<unistd.h>
#include<sys/syscall.h>
#include<stdio.h>
#include<string.h>
#include"Resource.h"
#include"mime.h"
#include "iostream"

//判断文件是否存在
int searchResource(const char* path);
//识别类型
int identifyType(const char* path,char* type);


#endif //WEBSERVER_RESOURCE_H
