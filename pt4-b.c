

/*

PROGRAM 4(b)



WAP USING FORK() AND EXEC() COMMANDS WHERE PARENT AND CHILD EXECUTE SAME PROGRAM,DIFFERENT CODE.

*/



#include<sys/wait.h>

#include<unistd.h>

#include<stdlib.h>

#include<stdio.h>

void main()

{

        int pid;

        pid=fork();

        if(pid<0)

        {

                fprintf(stderr,"Fork failed");

                exit(-1);

        }

        else if(pid>0)

        {

                printf("Hello,my pid is %d \n",pid);

        }

	   else 

	   {

			printf("hi,,,,my pid is %d \n",pid);

	   }

	   exit(0);

}



/*



OUTPUT



hi,,,,my pid is 0

Hello,my pid is 65408



*/



