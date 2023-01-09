#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char* argv[]){
    if(argc >= 2){
        int value = atoi(argv[argc-1]);
        value *= 2;
        printf("Twice: Current process id: %d, Current result: %d\n", getpid(), value);
        char val[12];
        sprintf(val, "%d", value);
        argv[argc-1] = val;
        argv = &argv[1];
        if(argc>2) execvp(argv[0], argv);
    }
    return 0;
}