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
   
    FILE *write_fp;
    char buffer[BUFSIZ+1];
    
    sprintf(buffer,"once upon a time, there was...\n");
    write_fp = popen("od -c", "w");
    if (write_fp != NULL) {
        fwrite(buffer, sizeof(char), strlen(buffer), write_fp);
        pclose(write_fp);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
    return 0;
}
