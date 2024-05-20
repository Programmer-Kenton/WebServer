#include "stdlib.h"
#include "Server/Server.h"

int main(int argc,char *argv[]) {
    // 初始化服务器
    if (initServer(argc < 2 ? 80 : atoi(argv[1]))){
        return -1;
    }
    // 运行服务器
    if (runServer(argc < 3 ? "/home" : argv[2])== -1){
        return -1;
    }

    // 终结化服务器
    deinitServer();
    return 0;
}
