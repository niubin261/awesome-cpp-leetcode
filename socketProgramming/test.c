//
// Created by niubin on 17-11-20.
//

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zconf.h>

int main(){
    char *buf;
    buf=(char*)malloc(100*1);
    bzero(buf,100);
    //char*buf1="hiiiiiiiip";
    //buf[0]='1';
    FILE *fp;
    fp=open("/tmp/temp2",O_WRONLY|O_CREAT);
    if(fp==NULL){
        printf("open file");
    }
    int len=read(fp,buf,100);
    //fputs(buf, stdout);
//    char s[100];
//    fgets(s,100,fp);
//    fputs(s,stdout);
    printf("%d",len);
    fputs(buf,stdout);
//    printf("%d",(int)sizeof(buf1));
//    int len1=fwrite(buf1,1,10,fp);
//    printf("%d",len1);
    fclose(fp);
    return 0;
}
//#include<unistd.h>
//#include<sys/types.h>
//#include<sys/stat.h>
//#include<fcntl.h>
//#include <stdlib.h>
//#include <stdio.h>
//int main()
//{
//    int fd,size;
//    char s []="Linux Programmer!\n",buffer[80];
//    fd=open("/tmp/temp",O_RDWR);
//    write(fd,s,sizeof(s));
//    close(fd);
//    fd=open("/tmp/temp",O_RDWR);
//    printf("%d",sizeof(buffer));
//    size=read(fd,buffer,sizeof(buffer));
//    close(fd);
//    printf("%s",buffer);
//}
#include <stdio.h>
#include<stdlib.h>
//#include<io.h>
//
//
//#include<conio.h>
//#include <zconf.h>
//
//int main(void)
//{
//    char msg[] = "This is a test!\n secend line\n";
//    char msgget[100];
//    int i = 0;
//    FILE* fstream;
//    fstream = fopen("test.txt","w+");        /*打开文件*/
//    if(fstream==NULL)
//    {
//        printf("Open file failed!\n");
//        exit(1);
//    }
//    fputs(msg, fstream);                /*写入文件*/
//    fflush(fstream);
//    close(fileno(fstream));
//    fstream=fopen("test.txt","r");
//    i = 0;
//    fgets(msgget,3,fstream) ;
//    fputs(msgget, stdout);
//    printf("\n");
//    fgets(msgget,100,fstream) ;/*从流中读取一行或者指定个数字符*/
//    fputs(msgget, stdout); /*送一个字符串到流中*/
//    return 0;
//}