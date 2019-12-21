#include "login.h"
#include <stdio.h>
#include <string.h>
Login::Login(QWidget *parent) : QWidget(parent)
{

}
int login(char *buf_user,char *buf_paswrd)
{
    FILE *fd;
    char buf[1024] = "",user[512],password[512];
    fd = fopen("../project_it/user.txt","r");
    if(fd == NULL)
        printf("--配置文件不存在--\n");
    while(fgets(buf,sizeof(buf),fd))
    {
        sscanf(buf,"%[^:]:%s",user,password);
        //printf("---%s=====\n",buf);
        if(strcmp(user,buf_user) == 0)
        {
            if(strcmp(password,buf_paswrd) == 0)
            {
                fclose(fd);
                return 1;//用户密码正确
            }
        }
    }
    fclose(fd);
    return 0;//用户和密码不正确
}

int regist(char *buf_user,char *buf_paswrd)
{
    FILE *fd;
    char buf[1024] = "",user[512];
    fd = fopen("../project_it/user.txt","r+");
    if(fd == NULL)
        printf("--配置文件不存在--\n");
    while(fgets(buf,sizeof(buf),fd))
    {
        sscanf(buf,"%[^:]",user);
        //printf("---%s=====\n",buf);
        if(strcmp(user,buf_user) == 0)
        {
            fclose(fd);
            return -1;//用户名重复
        }
    }
    sprintf(buf,"%s:%s\n",buf_user,buf_paswrd);
    fputs(buf,fd);
    fclose(fd);
    return 0;//注册成功
}
