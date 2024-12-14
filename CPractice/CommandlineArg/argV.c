#include <stdio.h>

int main(int argc, char* argv[]){
    printf("you enetered %d arguments\n", argc);
    for(int i = 0; i < argc; i++){
        printf("the arguments are: %s\n", argv[i]);
    }
    return 0;
}