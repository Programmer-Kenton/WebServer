/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 24-5-20 下午6:51
 * @Author Kenton
 */
#include "Server.h"



//初始化最大文件描述符数
static int initMaxFiles(void){
    //资源限制
    struct rlimit rl;
    if(getrlimit(RLIMIT_NOFILE,&rl) == -1){
        perror("getrlimit");
        return -1;
    }

    //如果当前进程最大文件描述符数小于系统极限
    if(rl.rlim_cur < rl.rlim_max){
        rl.rlim_cur = rl.rlim_max;
        if(setrlimit(RLIMIT_NOFILE,&rl) == -1){
            perror("setrlimit");
            return -1;
        }
    }
    return 0;
}

//初始化服务器
int initServer(short port){
    //初始化最大文件描述符数
    if(initMaxFiles() == -1){
        return -1;
    }
    //初始化信号
    if(initSignals() == -1){
        return -1;
    }
    //初始化套接字
    if(initSocket(port) == -1){
        return -1;
    }
    return 0;
}
//运行服务器
int runServer(const char* home){
    for(;;){
        //接受客户端的连接请求
        int conn = acceptClient();
        if(conn == -1){
            return -1;
        }
        //开线程,具有分离属性
        pthread_t tid;
        pthread_attr_t attr;//线程的属性
        pthread_attr_init(&attr);//初始化
        pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
        CA* ca = static_cast<CA *>(malloc(sizeof(CA)));
        ca->conn = conn;
        ca->home = home;
        int error = pthread_create(&tid,&attr,client,ca);
        if(error){
            fprintf(stderr,"pthread_create:%s\n",strerror(error));
            return -1;
        }
    }
    return 0;
}
//终结化服务器
void deinitServer(void){
    //终结化套接字
    deinitSocket();
}
