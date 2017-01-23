//
//  main.c
//  pipe4
//
//  Created by felix on 2017/1/18.
//  Copyright © 2017年 felix. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char * argv[]) {
    
    int data_processed;
    char buffer[BUFSIZ+1];
    int file_descriptor;
    
    memset(buffer, '\0', sizeof(buffer));
    sscanf(argv[1], "%d",&file_descriptor);
    data_processed = read(file_descriptor, buffer, BUFSIZ);
    printf("%d - read %bytes : %s \n",getgid(),data_processed,buffer);
    exit(EXIT_SUCCESS);
    
    return 0;
}
