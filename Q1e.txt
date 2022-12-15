//PROGRAM 1(e)

/*WAP (using fork() and/or exec() commands) WHERE  PARENT AND CHILD EXECUTE : AND BEFORE TERMINATING, THE PARENT WAITS FOR THE CHILD TO FINISH ITS TASK.*/



#include<stdio.h>

#include<stdlib.h>

#include<unistd.h>

void main()

{

        int pid;

        pid=fork();

        if(pid<0)

        {

                fprintf(stderr,"Fork failed");

                exit(-1);

        }

        else if(pid==0)

        {

                printf("child pid is : %d\n",pid);

        }

        else

        {

                wait(NULL);

                printf("parent pid is : %d\n",pid);

                exit(0);

        }

}



/*

OUTPUT



$ cc Q1_e.c

$ ./a.out

child pid is : 0

parent pid is : 3268

*/

