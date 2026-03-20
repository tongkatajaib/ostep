
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(void)
{

    int fd = open( "./2.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU );
    int ppid = fork();

    if ( ppid < 0 )
    {
        puts( "Fork Failed!" );
    }
    else if ( ppid == 0 )
    {
        short wr = write( fd, "Hello From Child\n", 18 );
        fprintf( stdout, "Child: %d bytes written\n", wr );
    }
    else 
    {
        wait(NULL);
        short wr = write( fd, "Hello From Parent\n", 19 );
        fprintf( stdout, "Parent: %d bytes written\n", wr );
    }


    return 0;
}
