//
//  main.c
//  popen2
//
//  Created by felix on 2017/1/16.
//  Copyright © 2017年 felix. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc,  const char * argv[]) {
    
    FILE *read_fp;
    char buffer[BUFSIZ+1];
    size_t chars_read;
    memset(buffer,'\0', sizeof(buffer));
    read_fp = popen("ps ax", "r");
    
    if (read_fp != NULL) {
        chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
        while (chars_read > 0) {
            buffer[chars_read - 1] = '\0';
            printf("Reading %d: - \n %p\n",BUFSIZ,read_fp);
            chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
        }
        pclose(read_fp);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
    return 0;
}
