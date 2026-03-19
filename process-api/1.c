/*
1. Write a program that calls fork(). Before calling fork(), have the
main process access a variable (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
What happens to the variable when both the child and parent change
the value of x?
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>



int main(void)
{

    int x = 100;

    int id = fork();
    
    if ( id < 0 ) 
    {
        puts( "Fork failed!" );
    }
    else if ( id == 0 ) 
    {
        puts( "Hello from child!" );
        puts( "Changing child's x" );
        x = 69;
        printf( "Child's x: %d\n", x );

    }
    else
    {
        wait(NULL);
        printf( "Child's PID: %d\n", id );
        puts( "Changing parent's x" );
        x = 130;
        printf( "Parent's x: %d\n\n", x );
    }

    return 0;
}
/*
 * When the main program sets x = 100 then fork(), the child
 * inherits the value of x = 100.
 * When we set x = 69 in the child, the child will have x = 69.
 * The same thing happens for the  parent.
 * Therefore, variables are inherited to child. But,
 * variables become independent on both child and parent afterwards.
 *
 */
