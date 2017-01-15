//
//  main.c
//  popen1.c
//
//  Created by felix on 2017/1/15.
//  Copyright © 2017年 felix. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    FILE *read_fp;
    char buffer[BUFSIZ+1];
    size_t chars_read;
    memset(buffer, '\0', sizeof(buffer));
    read_fp = popen("uname -a", "r");
    if (read_fp != NULL) {
        chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
        if (chars_read > 0) {
            printf("Outpu was : - \n%s \n",buffer);
        }
        pclose(read_fp);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);

    return 0;
}
