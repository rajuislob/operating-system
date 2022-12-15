#include <iostream>
#include <stdlib.h>
using namespace std;

struct Process {
	int pID;
	int arrivalTime;
	int burstTime;
	int completionTime;
	int waitingTime;
	int turnAroundTime;
};

void swapProcess(struct Process *a, struct Process *b)
{
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

void sortAccArrivalTime(struct Process *p, int n)
{
    for(int i=0; i < n-1; ++i)
    {
        if(p[i].arrivalTime > p[i+1].arrivalTime)
        {
            swapProcess(&p[i], &p[i+1]);
        }
    }
    return;
}

void sortAccPID(struct Process *p, int n)
{
    for(int i=0; i < n-1; ++i)
    {
        if(p[i].pID > p[i+1].pID)
        {
            swapProcess(&p[i], &p[i+1]);
        }
    }
    return;
}

void calcCompletionTime(struct Process *p, int n)
{
	int remainingTime[n];
	for(int i=0; i < n; ++i)
		remainingTime[i] = p[i].burstTime;
    int minIndex, time=0, count=0;

	for(time=0; count!=n; time++)
	{	
		minIndex = 0;
		for(int i = 0; i < n; ++i)
			if(p[i].arrivalTime <= time && remainingTime[i] < remainingTime[minIndex] && remainingTime[i] > 0)
				minIndex = i;
		
		if(remainingTime[minIndex] <= 0)
			continue;
		
		remainingTime[minIndex]--;

		if(remainingTime[minIndex] == 0)
		{
			count++;
			p[minIndex].completionTime = time + 1;
		}
	}
	return;
}

void calcTurnAroundTime(struct Process *p, int n)
{
	for(int i=0; i<n; ++i)
  	{
    	p[i].turnAroundTime = p[i].completionTime - p[i].arrivalTime;
  	}
  	return;
}

void calcWaitingTime(struct Process *p, int n)
{
  	for(int i=0; i<n; ++i)
  	{
    	p[i].waitingTime = p[i].turnAroundTime - p[i].burstTime;
  	}
  	return;
}

void printAvgTime(struct Process *p, int n)
{
    sortAccArrivalTime(p, n);
	calcCompletionTime(p, n);
	calcTurnAroundTime(p, n);
	calcWaitingTime(p, n);
    sortAccPID(p, n);


	cout << " SRTF CPU Scheduling" << endl;
	cout << " ------------------------------" << endl;
  	cout << "\n process -> { arrivalTime, burstTime, completionTime, turnAroundTime, waitingTime }\n";
  	for (int i=0; i<n; ++i)
  	{
   		cout << " P" << p[i].pID << "      -> { " << p[i].arrivalTime << " , " << p[i].burstTime << " , " << p[i].completionTime << " , " << p[i].turnAroundTime << " , " << p[i].waitingTime << " }\n";
  	}

  
  	int sumW = 0.0;
  	int sumT = 0.0;
  	for (int i=0; i<n; ++i)
  	{
    		sumW += p[i].waitingTime;
    		sumT += p[i].turnAroundTime;
  	}

  	
  	cout << "\n Average Waiting Time: " << sumW/n;
  	cout << "\n Average Turn Around Time: " << sumT/n << endl;

  	return;
}

int main()
{
	int n;

	cout << "\n Enter number of Processes: ";
	cin >> n;
	cout << endl;
	
	struct Process p[n];
	for(int i=0; i<n; ++i)
	{
		p[i].pID = i+1;
		cout << " Enter Arrival Time of Process " << i+1 << ": ";
		cin >> p[i].arrivalTime;
		cout << " Enter Burst Time of Process " << i+1 << ": ";
		cin >> p[i].burstTime;
		cout << endl;
	}
	
	printAvgTime(p, n);
	cout << endl;

	return 0;
}
