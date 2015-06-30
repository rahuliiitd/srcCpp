#include<iostream>

//This Program takes command line arguments as input

using namespace std;
void sort(int *,int);
void printArray(int*,int);

int main(int argc, char *argv[])
{
	/*cout<<"argc="<<argc;
	cout<<"\nargv : "<<argv[1];*/
	argc--;
	int i,*a=new int[argc];
	for (i=0;i<argc;i++)
	{
		a[i]=atoi(argv[i+1]);
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	sort(a,argc);
	cout<<"Sorted Array :\n";
	printArray(a,argc);
	return 0;
}

void sort(int *a,int argc)
{
	int i,j,temp;
	for (i=1;i<argc;i++)
	{
		temp=a[i];
		j=i-1;
		while (a[j]>temp && j>=0)
		{	a[j+1]=a[j];
			j--;
		}
		j++;
		a[j]=temp;
		cout<<"\nArray : ";
		printArray(a,argc);
	}
}	
		
void printArray(int *a,int len)
{
	for (int i=0;i<len;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}		
