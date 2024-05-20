/**
 * @Description Http模块头 接口实现
 * @Version 1.0.0
 * @Date 2024/5/20 14:54
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */
#include "Http.h"

//http请求的解析
int parseRequest(const char* req,HTTP_REQUEST* hreq){
    /*  GET /cpp/locale/setlocale.html HTTP/1.1\r\n
        Host: 192.168.222.128\r\n
        Connection: keep-alive\r\n
        User-Agent: Mozilla/5.0\r\n
        Accept: text/html\r\n
        Referer: http://192.168.222.128/cpp/locale.html\r\n\r\n
    */
    sscanf(req,"%s%s%s",hreq->method,hreq->path,hreq->protocol);
    char* connection = const_cast<char *>(strcasestr(req, "connection"));
    if(connection){
        sscanf(connection,"%*s%s",hreq->connection);
    }
    printf("%d.%ld > [%s][%s][%s][%s]\n",getpid(),syscall(SYS_gettid),
           hreq->method,hreq->path,hreq->protocol,hreq->connection);
    //判断请求方法
    if(strcasecmp(hreq->method,"get")){
        printf("%d.%ld > 无效的方法\n",getpid(),syscall(SYS_gettid));
        return -1;
    }
    //判断协议版本
    if(strcasecmp(hreq->protocol,"http/1.0") && strcasecmp(hreq->protocol,"http/1.1")){
        printf("%d.%ld > 无效协议\n",getpid(),syscall(SYS_gettid));
        return -1;
    }
    return 0;
}

//http响应的构造
int constructHead(const HTTP_RESPOND* hres,char* head){
    /*  HTTP/1.1 200 OK
        Server: LaozhangWebserver 4.0
        Date: Sat 03 Dec 2022 02:06:24
        Content-Type: text/html
        Content-Length: 38232
        Connection: keep-alive
    */
    char dateTime[32];
    time_t now = time(NULL);
    strftime(dateTime,sizeof(dateTime),"%a %d %b %Y %T",gmtime(&now));
    sprintf(head,"%s %d %s\r\n"
                 "Server: Kenton-Server 1.0\r\n"
                 "Date: %s\r\n"
                 "Content-Type: %s\r\n"
                 "Content-Length: %ld\r\n"
                 "Connection: %s\r\n\r\n",hres->protocol,hres->status,hres->desc,
            dateTime,hres->type,hres->length,hres->connection);
    return 0;
}

