#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int pid;       // process id
    pid = fork();  // create another process
    if (pid < 0) { // fail
        printf("\nFork failed\n");
        exit(-1);
    } else if (pid == 0) {                        // child
        execlp( "/ bin / ls", "ls", "- l", NULL); // execute ls
    } else {                                      // parent
        wait(NULL);                               // wait for child
        printf("\nchild complete\n");
        exit(0);
    }
}

/*	OUTPUT:

------------------[OUTPUT]-----------------

guest-glcbIs@ubuntu:~$gcc –o lsc.out lsc.c
guest-glcbIs@ubuntu:~$./lsc.out
total 100
-rwxrwx—x 1 guest-glcbls guest-glcbls 140 2012-07-06 14:55 f1
drwxrwxr-x 4 guest-glcbls guest-glcbls 140 2012-07-06 14:40 dir1
child complete

--------------[END-OF-OUTPUT]--------------

*/
