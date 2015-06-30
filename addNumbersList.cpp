#include<iostream>
#include "listClass.cpp"

using namespace std;

List insertInList(int);
int returnSum(List);

int main()
{
	int n1,n2;
	cout<<"Enter Number 1 ";
	cin>>n1;
	cout<<"\nEnter number 2 ";
	cin>>n2;
	List a=insertInList(n1);
	List b=insertInList(n2);
	cout<<"Sum="<<returnSum(a)+returnSum(b)<<"\n";
	List c=insertInList(returnSum(a)+returnSum(b));
	c.printList();
	return 0;
}

List insertInList(int n)
{
	List a;
	int temp=n,l;
	while (temp>0)
	{
		l=temp%10;
		temp/=10;
		a.insert(l);
	}
	return a;
}

int returnSum(List a)
{
	int len=a.getLength(),i,loc=1,sum=0;
	for (i=1;i<=len;i++,loc=loc*10)
	{
		sum+=loc*a.getNodeValue(i);
	}
	return sum;
}
			
