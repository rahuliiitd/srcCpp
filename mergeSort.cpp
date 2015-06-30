#include<iostream>

void mergeSort(int*,int,int);
void merge(int*,int,int,int);
void printArray(int*,int);

int main()
{
	int a[]={5,4,3,2,1,0};
	mergeSort(a,0,5);
	printArray(a,6);
}

void printArray(int *a,int len)
{
	//int len=sizeof(a)/sizeof(int);
	for (int i=0;i<len;i++)
	{
		std::cout<<a[i]<<" ";
	}
}

void mergeSort(int *a,int x,int y)
{
	if (x<y)
	{
		int z=(x+y)/2;
		mergeSort(a,x,z);
		mergeSort(a,z+1,y);
		merge(a,x,z,y);
	}
}

void merge(int *a,int low,int mid,int high)
{
	int i=low,j=mid+1,k=0;
	int *b=new int[high-low+1];
	while (i<=mid && j<=high)
	{
		if (a[i]<a[j])
		{
			b[k]=a[i];
			i++;
		}
		else
		{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	if (i>mid)
	{	
		while (j<=high)
		{
			b[k]=a[j];
			j++;
			k++;
		}
	}
	else
	{	
		while (i<=mid)
		{
			b[k]=a[i];
			i++;
			k++;
		}
	}
	
	for (i=low,j=0;i<=high;i++,j++)
		a[i]=b[j];
	
	delete[] b;
}
