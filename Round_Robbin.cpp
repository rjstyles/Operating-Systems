/*
	Written by Rajeev Singh
	Email: rajeevsinxh786@gmail.com
	Round Robbin Scheduling algorithm
*/

#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

//Defining Quantum time for CPU
#define QT 2

/* 
	Data for processes.Each row is a process having execution time as element 0 
	and 2nd element as arrival time.
	Can also be user input!
*/
int Data[][2]={{5,2},{3,0},{1,5},{9,6},{6,4}};

int currTime,currProcess=-1,k;
int Comp[5],Arr[5],ExeTimeLeft[5]={5,3,1,9,6};

//To count the no. of completed processes..

int noOfCom()
{
	int n=0;
	for(int i=0;i<5;i++)
	{
		if(Comp[i]==1)
		n++;
	}
	return n;
}

//To count the total length of the Scheduler...

int calcTotalSch()
{
	int sum=0;
	for(int i=0;i<5;i++)
		sum+=ceil(Data[i][0]/2);
	return sum;	
}

/*
	Defining a Scheduler array of Structure type.
	startTime is the time at start of the process in cpu
	endTime is the time at which the contact switching occurs or the process ends.. 
*/
typedef struct sch
{
	int startTime;
	int endTime;
	int pid;
} Sch;

//to display the Scheduler array...

void display(Sch Scheduler[])
{
	int i=0;
	cout<<"[";
	for(;i<13;i++)
	cout<<"P"<<Scheduler[i].pid+1<<"("<<Scheduler[i].startTime<<"-"<<Scheduler[i].endTime<<")"<<"|";
	cout<<"P"<<Scheduler[i].pid+1<<"("<<Scheduler[i].startTime<<"-"<<Scheduler[i].endTime<<")";
	cout<<"]"<<endl;
}

int main()
{
	const int totalSch=calcTotalSch();
	Sch Scheduler[totalSch];
	queue<int> readyQueue;
	
	while(noOfCom()<5)
	{
		for(int i=0;i<5;i++)
		{
			if(Data[i][1]<=currTime && Arr[i]!=1)
			{
				Arr[i]=1;
				readyQueue.push(i);				
			}					
		}

		if(currProcess!=-1 && ExeTimeLeft[currProcess]!=0)
		{
			readyQueue.push(currProcess);
		}
		
		currProcess=readyQueue.front();
		readyQueue.pop();
		
		Scheduler[k].pid=currProcess;
		Scheduler[k].startTime=currTime;
		if(ExeTimeLeft[currProcess]>QT)
		{
			Scheduler[k].endTime=Scheduler[k].startTime + QT;
			ExeTimeLeft[currProcess]-= QT;
		}
		else
		{
			Scheduler[k].endTime=Scheduler[k].startTime + ExeTimeLeft[currProcess];
			ExeTimeLeft[currProcess]=0;
			Comp[currProcess]=1; 
		}
		
		currTime=Scheduler[k].endTime;
		k++;
	}
	
	display(Scheduler);
	
	return 0;	
}
 
