#include <iostream>
using namespace std;
template <class s>
class qnode{
	public:
	s info;
	qnode* next;

		qnode(s i=0,qnode* n=NULL)
		{
			info=i;
			next=n;
		}
	friend class queuell;
};
template <class t>
class queueasll{
	qnode<t> *cursor;
	public :
		queuell()
		{
			cursor=NULL;
		}
		bool empty()
		{ 
			return cursor==NULL;
		}
		int size()
		{
			if(empty())
			{
				return 0;
			}
			int c=1;
			qnode<t> *q=cursor->next;
			while(q!=cursor)
			{
				q=q->next;
				c++;
			}
			return c;
			
		}
		void enqueue(t ele)
		{
			if(empty())
			{
				cursor=new qnode<t>(ele);
				
			}
			if(size()==1)
				{
					qnode<t> *p=cursor;
					cursor->next=new qnode<t>(ele);
					cursor=cursor->next;
					cursor->next=p;
					return;
				}
			else{
				qnode<t> *p=new qnode<t>(ele);
				p->next=cursor->next;
				cursor->next=p->next;
			}
								
			
		}
		void dequeue()
		{
			if(empty())
			{
				cout<<"queue is empty "<<endl;
				return;
			}
			if(size()==1)
			{
				qnode<t> *p=cursor;
				cursor=NULL;
				delete(p);
			}
			else
			{
				qnode<t> *p=cursor->next;
				cursor->next=p->next;
				delete(p);
			}
		}
		t front()
		{
			if(!empty())
			{
				return cursor->next->info;
			}
		}
		t rear()
		{
			if(!empty())
			{
				return cursor->info;
			}
		}
		
};
int main()
{
	
	queueasll<int>q;
	int x,ch;
	do
	{
		cout<<"Enter choice \n1.Enqueue \n2.Dequeue \n3.GetFront \n4.GetRear \n5.GetSize \n6.Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
					cout<<"Enter Element\n";
					cin>>x;
					q.enqueue(x);
					break;
			case 2:
					cout<<"Element Deleted\n";
					q.dequeue();
					break;
			case 3:
					cout<<"The element at front is:"<<q.front()<<endl;
					break;
			case 4:
					cout<<"Element at Rear is:"<<q.rear()<<endl;
					break;
			case 5:	
					cout<<"Current size is:"<<q.size()<<endl;
					break;
			case 6:
					return 0;
			default:
					cout<<"wrong choice entered "<<endl;
				
		}
		cout<<"----------------------------------------------------------------------------------------------------------------\n";
	}
	while(true);
	return 0;
}
