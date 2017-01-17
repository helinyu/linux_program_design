//
//  main.c
//  popen2
//
//  Created by felix on 2017/1/16.
//  Copyright © 2017年 felix. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc,  const char * argv[]) {
   
    // (1)这个部分和前面的程序一部分相同
    ssize_t data_processed;
    int file_pipes[2];
    const char some_data[] ="123";
    char buffer[BUFSIZ + 1];
    pid_t fork_result;
    
    memset(buffer, '\0', sizeof(buffer));
    
    if (pipe(file_pipes) == 0) {
        fork_result = fork();
        if (fork_result == -1) {
            fprintf(stderr, "Fork failrure");
            exit(EXIT_FAILURE);
        }
      
        //(2) 在确认fork调用成功后，如果fork_result 等于零，就说明我们子进程中，如下
        if (fork_result == 0 ) {
            data_processed = read(file_pipes[0], buffer, BUFSIZ);
            printf("Read %zd bytes : %s \n",data_processed,buffer);
            exit(EXIT_SUCCESS);
        }//(3) 否则，我们肯定是父进程
        else{
            data_processed = write(file_pipes[1], some_data, strlen(some_data));
            printf("Wrote %zd bytes \n",data_processed);
        }
    }
    exit(EXIT_SUCCESS);
    
    return 0;
}
