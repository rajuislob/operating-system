#include<iostream>
using namespace std;
class process
{
	public:
	int *p,*bt,*at,*pr,*wait,*turn;

};
#define MAX 9999
struct proc
{
    int no,at,bt,rt,ct,tat,wt,pri,temp;
};


struct proc read(int i)
{
    struct proc p;
    p.no=i;
    cout<<"Enter Arrival Time "<<endl;
    cin>>p.at;
    cout<<"Enter Burst Time "<<endl;
    cin>>p.bt;
    p.rt=p.bt;
    return p;
}

class prior:public process
{	public:
	int n;
	prior(int n)                                       {                                                         this->n=n;                                        p=new int[this->n];                               at=new int[this->n];                              bt=new int[this->n];                              wait=new int[this->n]();                          turn=new int[this->n](); 
		pr=new int[this->n];
	}

	void data()
        {	
                for(int i=0;i<n;i++)
                {                                                         p[i]=i+1;
	cout<<"Enter Arrival time\n";
			cin>>at[i]; 
		cout<<"Enter Burst time\n";
		cin>>bt[i];
		cout<<"Enter Priority\n";
			cin>>pr[i];
                }     
	}
	void sort()                                       {                                                         int min;                                       for(int i=0;i<n-1;i++)                            {       min=i;                                            for(int j=i+1;j<n;j++)                    {                                                   if(pr[min]>pr[j]||at[min]>at[j])min=j;                  }                                                         if(min!=i)                                   {                                                 swap(bt[i],bt[min]);
          swap(at[i],at[min]);                              swap(p[i],p[min]);  
	  swap(pr[i],pr[min]);
	}                                         }		                                    }
	void time()                                       {                                                         wait[0]=0;int t=0;                                turn[0]=bt[0];                                    for(int i=1;i<n;i++)                              {                                                      int j=i;                                     while(j--)                                        {                                                    turn[i]+=at[j]+bt[j];                             wait[i]+=bt[j];                                   t+=bt[j];                                 }                                                 if(t<=at[i])                                      {                                                         wait[i]=0;                                turn[i]=bt[i];                                    }                                                 else    
		{
		turn[i]=wait[i]+bt[i]-at[i];                         wait[i]-=at[i];                                       }     
	}
	}
void disp()                                       {                                                         double sumw=0,sumt=0;                          printf("\nProcess\tAT\tBT\tWT\tTAT\tPR\n");                                                   		 for(int i=0;i<n;i++)                              {                                                 sumw+=wait[i];                                    sumt+=turn[i];                                  cout<<"P"<<p[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<wait[i]<<"\t"<<turn[i]<<endl;           
}
	sumw/=n;sumt/=n;
	printf("\nAverage TurnAroundTime=%f\nAverage WaitingTime=%f",sumt,sumw); 
}
};
struct proc readq(int i)
{
    struct proc p;
    printf("\nProcess No: %d\n",i);
    p.no=i;
    printf("Enter Arrival Time: ");
    scanf("%d",&p.at);
    printf("Enter Burst Time: ");
    scanf("%d",&p.bt);
    p.rt=p.bt;
    printf("Enter Priority: ");
    scanf("%d",&p.pri);
    p.temp=p.pri;
    return p;
}






int main()
{	int n;int ch;
	cout<<"Enter no. of Processes\n";                 cin>>n;

		prior p(n);
		p.data();
		p.sort();
		p.time();
		p.disp();
	
	return 0;
}

		  


