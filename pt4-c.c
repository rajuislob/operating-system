/*

PROGRAM 



WAP USING FORK() AND EXEC() COMMANDS WHERE PARENT AND CHILD EXECUTE DIFFERENT PROGRAMS BY SPECIFYING A PATH

*/



#include<stdlib.h>

#include<stdio.h>

#include<unistd.h>

void main()

{

	int pid;

	pid=fork();

	if(pid<0)

	{

	fprintf(stderr,"Fork Failed");

	exit(-1);

	}

	else if(pid==0)

	{

		execlp("/bin/ls","ls",NULL);

	}

	else

	{

		printf("CHILD COMPLETE");

		exit(0);

	}

}



/*

OUTPUT



CHILD COMPLETE$ Music.exe       q1_b.exe        q2_m.o          q3_f.o

Prac_neha.txt   q1_b.o          q3_a.c          q5_a.c

a.out           q1_c.c          q3_a.o          q5_a.o

fcfs.c          q1_c.o          q3_b.c          q5_b.c

fcfs.o          q1_d.c          q3_b.o          q5_b.o

fcfs_2          q1_d.o          q3_c.c          rr.c

fcfs_2.c        q1_e.c          q3_c.o          rr.o

fcfs_2.o        q1_e.o          q3_d.c          sq.c

file.c          q1_f.c          q3_d.o          sq.o

q1_a.c          q2.c            q3_e.c

q1_a.o          q2.o            q3_e.o

q1_b.c          q2_m.c          q3_f.c



*/
