#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <pthread.h>
#define MAX_BUF_LEN 1024
#define MAX_FILENAME_LEN 1024
#define TRUE 1
FILE *fp;
char buf[MAX_BUF_LEN]={0};
char file_name[MAX_BUF_LEN]={0};

void error_print(char * ptr){
    perror(ptr);
    exit(EXIT_FAILURE);
}

void quit_tranmission(int sig) {
    printf("recv a quit signal = %d\n",sig);
    exit(EXIT_SUCCESS);
}
int length(char*char_ptr){
    int length=0;
    while(*char_ptr++){
        length++;
    }
    return length;

}
void *thread_recv(void *arg);
void *thread_send(void *arg);
int main(int argc,char**argv){
    if(argc!=2){
        error_print("usage:a.out <IPaddress>");
    }


    int sockfd = socket(AF_INET6, SOCK_STREAM, 0);
    if(sockfd < 0)

        error_print("socket");
    struct sockaddr_in6 server_addr;
    bzero(&server_addr,sizeof(server_addr));
    server_addr.sin6_family = AF_INET6;
    server_addr.sin6_port = htons(8004);
    server_addr.sin6_addr = in6addr_any;
    //inet_aton("127.0.0.1",&server_addr.sin_addr);
    if(inet_pton(AF_INET6,argv[1],&server_addr.sin6_addr));
    if((connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr))) < 0)
        error_print("connect");
    //printf("hello\n");
    pthread_t tid_send;
    pthread_t tid_recv;
    int error;
    error= pthread_create(&tid_recv, NULL, thread_recv, &sockfd);
    if (error ){
        error_print("Thread creation failed");
    }

    error= pthread_create(&tid_send, NULL, thread_send, &sockfd);
    if (error ){
        error_print("Thread creation failed");
    }

    while(TRUE){
    }
}
void*thread_recv(void *arg){
    //printf("hello1\n");
    while(TRUE){
        bzero(buf,MAX_BUF_LEN);
        int ret = recv(*((int *)arg),buf,MAX_BUF_LEN,0);

        if(ret==-1||ret==0){
            error_print("read");
        } else {
            if(buf[0]=='#'){
                fputs("ops,I will recv a file\n",stdout);
                int fd=open("/tmp/temp_client",O_RDWR);
                if(fd==-1){
                    error_print("open file");
                }
                int len=length(buf);
                buf[len-1]='\0';
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
void*thread_send(void *arg){
    bzero(buf,MAX_BUF_LEN);
    while(fgets(buf,MAX_BUF_LEN, stdin) != NULL){
        if(buf[0]=='#'){
            fputs("please input the file name\n",stdout);
            fscanf(stdin,"%s",file_name);
            int fd;
            if((fd=open(file_name,O_RDWR))==-1){
                error_print("open file ");
            }
            //bzero(buf,MAX_FILENAME_LEN);
            char*file_buf=buf;
            file_buf++;
            int file_len=read(fd,file_buf,MAX_BUF_LEN);
            if(file_len<0){
                error_print("read file");
            }
            close(fd);
            int  len=length(buf);

            //printf("send len:%d\n",len);
            //fputs(buf,stdout);
            int ret=send(*((int*)arg),buf,len,0);
            if(ret==-1){
                error_print("write");
            }
        }else{
            int  len=length(buf);
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






