#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <fcntl.h>
#define PORT 8004
#define TRUE 1
#define MAX_BUF_LEN 1024
#define MAX_FILENAME_LEN 1024
char buf[MAX_BUF_LEN]={0};
int length(char*char_ptr){
    int length=0;
    while(*char_ptr++){
        length++;
    }
    return length;
}
char file_name[MAX_BUF_LEN]={0};
void *thread_recv(void *arg);
void *thread_send(void *argue);
void error_print(char * ptr)
{
    perror(ptr);
    exit(EXIT_FAILURE);
}
int main() {
    int listenfd=socket(AF_INET6, SOCK_STREAM,0);
    if(listenfd<0)  {


        error_print("socket");
    }
    struct sockaddr_in6 serveraddr;
    bzero((char *)&serveraddr,sizeof(serveraddr));
    serveraddr.sin6_family=AF_INET6;
    serveraddr.sin6_addr=in6addr_any;
    serveraddr.sin6_port=htons(PORT);
    if(bind(listenfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr))<0)  {

        error_print("connect");
    }
    if(listen(listenfd,10)<0)  {
        error_print("listen error");

    }
    struct sockaddr_in6 clientaddr;
    int clientlen;
    clientlen=sizeof(clientaddr);

    pthread_t tid,tid1;
    int socketfd=accept(listenfd,(struct sockaddr *)&clientaddr, &clientlen);
    pthread_create(&tid, NULL, thread_recv, &socketfd);

    pthread_create(&tid1, NULL, thread_send, &socketfd);

    while(TRUE){
    }
}
void *thread_recv(void *arg)   {
    while(TRUE){
        bzero(buf,MAX_BUF_LEN);
        int ret=recv(*((int *)arg),buf,MAX_BUF_LEN,0);
        if(ret==-1||ret==0){
            error_print("read");
        } else {
            if(buf[0]=='#'){
                fputs("ops,I will recv a file\n",stdout);
                int fd=open("/tmp/temp_server",O_RDWR);
                if(fd==-1){
                    error_print("open file");
                }
                int len=length(buf);
                buf[len-1]='\0';
                //fputs(buf,stdout);
                //printf("len:%d\n",length(buf)-1);
                write(fd,buf+1,length(buf)-1);
            } else{
                if(strcmp(buf,"END")==0){
                    close(*((int *)arg));
                }else{

                    printf(">>");
                    fputs(buf,stdout);
                }
            }
        }
    }
    return NULL;
}
void *thread_send(void *arg)   {

    bzero(buf,MAX_BUF_LEN);
    while(fgets(buf,MAX_BUF_LEN, stdin) != NULL){

        if(buf[0]=='#'){
            fputs("please input the file name\n",stdout);

            bzero(file_name,MAX_FILENAME_LEN);
            fscanf(stdin,"%s",file_name);
            int fd;
            if((fd=open(file_name,O_RDWR))==-1){
                error_print("open file ");
            }
            //bzero(buf,MAX_FILENAME_LEN);
            char*file_buf=buf;
            file_buf++;
            int file_len=read(fd,file_buf,MAX_BUF_LEN);
            //printf("file_len=%d\n",file_len);
            if(file_len<0){
                error_print("read file");
            }
            close(fd);
            int len=(length(buf));
            //printf("send len:%d\n",len);
            //fputs(buf,stdout);
            int ret=send(*((int*)arg),buf,len,0);
            if(ret==-1){
                error_print("write");
            }
        }else{
            int len=(length(buf));
            //printf("send len:%d\n",len);
            //fputs(buf,stdout);
            int ret=send(*((int*)arg),buf,len,0);
            if(ret==-1){
                error_print("write");
            }
        }

        bzero(buf,MAX_BUF_LEN);
    }
    return NULL;
}

