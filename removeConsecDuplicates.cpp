#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T,i,j,k,tot;
    string s,res="";
    cin>>T;
    for (i=1;i<=T;i++)
        {
            cin>>s;
		res="";
            tot=0;
            for (j=0;j<s.length();j++)
            {
                    if (res=="")
                    {
                        res+=s[j];
                        continue;
                    }
                    
                    if (s[j]==res.back())
                        {
                        continue;
                    }
                    else
                        {
                            res+=s[j];
                    }
            }
		cout<<"\ns="<<s<<" res="<<res<<"\n";
            cout<<s.length()-res.length()<<"\n";
    }
    return 0;
}
