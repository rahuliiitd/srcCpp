#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct duration
{
	int num;
	double start,end;
};

bool sortFunc(duration a,duration b)
{
	return (a.end<b.end);
}

void printDurations(vector<duration> d)
{
	for (auto i=d.begin();i!=d.end();i++)
	{
		cout<<"Duration Number="<<i->num<<" Start="<<i->start<<" End="<<i->end<<"\n";
	}
}

int main()
{
	double dStart,dEnd,e;
	int intervals,i;
	vector<duration> D;
	duration d;
	cout<<"Enter Start and End times\n";
	cin>>dStart>>dEnd;
	cout<<"\nEnter number of intervals ";
	cin>>intervals;
	for (i=1;i<=intervals;i++)
	{
		cout<<"\nEnter Interval "<<i<<" Start and End time ";
		d.num=i;
		cin>>d.start>>d.end;
		D.push_back(d);
	}
	sort(D.begin(),D.end(),sortFunc);
	e=(D.begin())->start;
	for (auto i=D.begin();i!=D.end();i++)
	{
		if (i->start>=e)
		{
			cout<<"Interval "<<i->num<<" chosen\n";
			e=i->end;
		}
	}	
	//printDurations(D);*/
	return 0;
}
		 
