//
//  main.c
//  pipe3
//
//  Created by felix on 2017/1/18.
//  Copyright © 2017年 felix. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    int data_processed;
    int file_pipe[2];
    const char some_data[] ="12345";
    ssize_t buffer[BUFSIZ +1];
    pid_t fork_result;
    
    memset(buffer, '\0', sizeof(buffer));
    
    if (pipe(file_pipe) == 0 ) {
        fork_result = fork();
        if (fork_result == (pid_t)-1) {
            fprintf(stderr, "Fork failture");
            exit(EXIT_FAILURE);
        }
        
        if (fork_result == 0) {
            sprintf(buffer, "%d",file_pipe[0]);
            (void)execl("pipe4", "pipe4",buffer,(char*)0);
            exit(EXIT_FAILURE);
        }else{
            data_processed = write(file_pipe[1], some_data, strlen(some_data));
            printf("%d -wrote %d bytes \n",getgid(),data_processed);
        }
    }
    exit(EXIT_SUCCESS);
    
    return 0;
}
