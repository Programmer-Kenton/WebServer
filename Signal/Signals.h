/**
 * @Description 信号模块 头文件
 * @Version 1.0.0
 * @Date 2024/5/20 14:54
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#ifndef WEBSERVER_SIGNALS_H
#define WEBSERVER_SIGNALS_H

#include<unistd.h>
#include<sys/syscall.h>
#include<signal.h>
#include<stdio.h>

//初始化信号,忽略大部分
int initSignals(void);


#endif //WEBSERVER_SIGNALS_H
