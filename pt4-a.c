/*

PROGRAM 1



WAP USING FORK() AND EXEC() COMMANDS WHERE PARENT AND CHILD EXECUTE SAME PROGRAM,SAME CODE

*/



#include<unistd.h>

#include<stdlib.h>

#include<stdio.h>

int main()

{

	int pid;

	pid=fork();

	if(pid<0)

	{

		fprintf(stderr,"Fork failed");

		exit(1);

	}

	else

	{

		printf("Hello,my pid is %d \n",pid);

		exit(-1);

	}

}





/*

OUTPUT



Hello,my pid is 0

Hello,my pid is 64576



*/

