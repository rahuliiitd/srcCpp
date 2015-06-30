#include<iostream>
#include<string>

using namespace std;

void printBrackets(string,int,int,int);

int main()
{
	printBrackets("",0,0,4);
	return 0;
}

void printBrackets(string output,int open,int close,int n)
{
	if ((open==n) && (close==n))
	{
		cout<<"\n"<<output;
	}
	else
	{
		if (open<n)
			printBrackets(output+"(",open+1,close,n);
		if (close<open)
			printBrackets(output+")",open,close+1,n);
	}
}
