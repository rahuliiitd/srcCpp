#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>

using namespace std;

bool isFunny(string,string);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T,i;
    cin>>T;
    string s,r;
    for (i=1;i<=T;i++)
    {   
            cin>>s;
            r=s;
            reverse(r.begin(),r.end());
            if (isFunny(s,r))
                cout<<"Funny\n";
            else
               cout<<"Not Funny\n";
    }       
    return 0;
}

bool isFunny(string s,string r)
    {
        bool funny=true;
        for (int i=1;i<s.length();i++)
            {
                if (abs(s[i]-s[i-1])!=abs(r[i]-r[i-1]))
                    {
                        funny=false;
                        break;
                }
        }
        
        return funny;
}
