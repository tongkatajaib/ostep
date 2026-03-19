
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>


int main(void)
{

    int pid = fork();

    if ( pid == 0 ) {
        char *args[3];
        args[0] = "ls";
        args[1] = "-l";
        args[2] = NULL;

        execvp( args[0] , args );
        puts( "Gone!" );
    }
    else if ( pid < 0 ) {
        puts( "Fork Error!" );
    }
    else {
        int retw = wait(NULL);
        puts( " This Parent! " );
    }


    return 0;
}
