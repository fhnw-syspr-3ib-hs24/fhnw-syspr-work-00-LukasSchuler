#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

int main (int argc, char* argv[]) {

    if(argc<2) {
        printf("Provide a filepath.");
        return 1;
    }

    if(argc>2){
        printf("Only one argument allowed");
        return 1;
    }
    
    int fd = open(argv[1], O_RDONLY);

    if(fd == -1) {
            printf("%d\\n", errno);
            return 1;
        }

    int fdn = open("copied.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    if(fdn == -1) {
            printf("%d\\n", errno);
            return 1;
        }
    
    char buf[32];
    ssize_t r = 1;
    ssize_t w = 1;
    
    while(r>0) {
        r = read(fd, buf, 32);
        if(r == -1) {
            printf("%d\\n", errno);
            return 1;
        }
        w = write(fdn, buf, r);
        if(w == -1) {
            printf("%d\\n", errno);
            return 1;
        }
    }

}