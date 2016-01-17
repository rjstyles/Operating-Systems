/*
	Written by Rajeev Singh
	Email: rajeevsinxh786@gmail.com
	Shortest job first(SJF) Algorithm
*/

#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

int Data[][2]={{2,0},{5,3},{9,1},{6,4},{1,8}};
int Com[5],Arr[5],k;
int currTime,currProcess=0;

typedef struct sch 
{
	int startTime;
	int endTime;
	int pid;
}STU;

int calcLen(int QT)
{
	double sum=0;
	for(int i=0;i<5;i++)
	{
		double tmp=(double)Data[i][0]/QT;
		sum+=ceil(tmp); 	
	}
	return sum;	
}

int noOfCompProcess()
{
	int n=0;
	for(int i=0;i<5;i++)
	{
		if(Com[i]==1)
		n++;
	}
	return n;
}

int findMinProcess()
{
	int pid=0,n=0,min;
	for(int i=0;i<5;i++)
	{
		if(Arr[i]==1 && Com[i]!=1)
		{
			n++;
			if(n==1)
			{
				pid=i;
				min=Data[i][0];
			}
			else
			{
				if(Data[i][0]<min)
				{
					pid=i;	
					min=Data[i][0];
				}
			}
		}
	}
	return pid;
}

void display(struct sch Scheduler[],int l)
{
	int i=0;
	cout<<"[";
	for(;i<l-1;i++)
	cout<<"P"<<Scheduler[i].pid+1<<"("<<Scheduler[i].startTime<<"-"<<Scheduler[i].endTime<<")"<<"|";
	cout<<"P"<<Scheduler[i].pid+1<<"("<<Scheduler[i].startTime<<"-"<<Scheduler[i].endTime<<")";
	cout<<"]"<<endl;
}

int main(int args,char** argv)
{
	if(args>1 && args<3)
	{
		const char c=argv[1][0];
		int QT=atoi(&c);
		if(QT>0)
		{
			const int MAX=calcLen(QT);
			STU SchedulingQueue[MAX];
		
			while(noOfCompProcess()<5)
			{
				for(int i=0;i<5;i++)
				{
					if(Data[i][1]<=currTime)
					Arr[i]=1;			
				}
		
				currProcess=findMinProcess();
		
				if(Data[currProcess][0]>QT)
				{
					Data[currProcess][0]-=QT;
					SchedulingQueue[k].pid=currProcess;
					SchedulingQueue[k].startTime=currTime;
					SchedulingQueue[k].endTime=currTime+QT;
					currTime+=QT;
				}
				else
				{
					SchedulingQueue[k].pid=currProcess;
					SchedulingQueue[k].startTime=currTime;
					SchedulingQueue[k].endTime=currTime+Data[currProcess][0];
					currTime+=Data[currProcess][0];
					Data[currProcess][0]=0;
					Com[currProcess]=1;
				}
				k++;
			}
	
			display(SchedulingQueue,MAX);
			}
		else
			cout<<"Invalid Quantum Time..!!\n";		
	}
	else
		cout<<"Invalid Quantum Time..!!\n";
}
