#include <string.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
    int cur = 1; //ignore 1st arg
    int error = 0;
    while (cur < argc && error == 0) {
        char* p = *(argv + cur);
        while(*p!='\0') {
            if(*p < 'a' || *p > 'z') {
                printf("%s", "Error");
                error = 1;
                break;
            }
            p++;
        }
        cur++;
    }
    if(error == 0){
        int i = 1; //ignore 1st arg
        while (i < argc) {
        printf("%s\n", argv[i]);
        i++;
        }
    }
    return 0;
}
