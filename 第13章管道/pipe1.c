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
   
    ssize_t data_processed;
    int file_pipes[2];
    const char some_data[] = "123";
    char buffer[BUFSIZ+1];
    
    memset(buffer, '\0', sizeof(buffer));
    
    if (pipe(file_pipes) == 0) {
        data_processed = write(file_pipes[1], some_data, strlen(some_data));
        // 文件描述符是从[1]中写进去
        printf("Wrote %zd bytes \n",data_processed);
        data_processed = read(file_pipes[0], buffer, BUFSIZ);
        // 文件描述符是从[0]这里读取出来
        printf("Read %zd bytes : %s \n",data_processed,buffer);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
    return 0;
}