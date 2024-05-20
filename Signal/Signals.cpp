/**
 * @Description 信号模块 接口实现
 * @Version 1.0.0
 * @Date 2024/5/20 14:54
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include "Signals.h"

//初始化信号
int initSignals(void){
    printf("%d.%ld > 忽略大部分信号\n",getpid(),syscall(SYS_gettid));
    for(int signum = SIGHUP;signum <= SIGRTMAX;signum++){
        if(signum != SIGINT && signum != SIGTERM){
            signal(signum,SIG_IGN);
        }
    }
    return 0;
}

