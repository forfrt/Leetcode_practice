#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#define K 1024
#define WRITELEN (129*K)

int main(void){
    int result=-1;
    int fd[2], nbytes;
    pid_t pid;
    char string[WRITELEN]="hello my pipe 2014!";
    char readbuffer[10*K];

    int *read_fd=&fd[0];
    int *write_fd=&fd[1];

    result=pipe(fd);
    if(-1 == result){
        printf("fail to create pipe");
        return -1;
    }

    pid=fork();
    if(-1==pid){
        printf("fail to fork");
        return -1;
    }
    if(0==pid){
        printf("Here is child process\n");
        fflush(stdout);
        int write_size=WRITELEN;
        result=0;
        close(*read_fd);
        while(write_size>0){
            result=write(*write_fd, string, write_size);
            printf("Here is child process 1\n");
            if(result>0){
                write_size-=result;
                printf("write %d bytes data, the rest is %d bytes\n", result, write_size);
            } else{
                //sleep(1);
            }
        }
        printf("Here is child process END\n");
        return 0;
    } else{
        close(*write_fd);
        printf("Here is parent process\n");
        fflush(stdout);
        while(1){
            nbytes=read(*read_fd, readbuffer, sizeof(readbuffer));
            printf("Here is parent process 1\n");
            if(nbytes<=0){
                printf("no data to write\n");
                break;
            }
            printf("receive %d bytes data: %s\n", nbytes, readbuffer);
        }
        printf("Here is parent process END\n");
    }
    return 0;
}
