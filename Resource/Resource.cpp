/**
 * @Description 资源模块 接口实现
 * @Version 1.0.0
 * @Date 2024/5/20 14:54
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include "Resource.h"

//判断文件是否存在
int searchResource(const char* path){
    return access(path,R_OK);
}

//识别类型
int identifyType(const char* path,char* type){
    // /ho.me/c/error.html
    //确定拓展名
    char* suffix = const_cast<char *>(strrchr(path, '.'));
    if(suffix == NULL){
        printf("%d.%ld > 无法获取拓展名\n",getpid(),syscall(SYS_gettid));
        return -1;
    }
    for(int i = 0;i < sizeof(s_mime) / sizeof(s_mime[0]);i++){
        if(strcasecmp(suffix,s_mime[i].suffix) == 0){
            strcpy(type,s_mime[i].type);
            return 0;
        }
    }
    printf("%d.%ld > 不可识别的资源类型\n",getpid(),syscall(SYS_gettid));
    return -1;
}


