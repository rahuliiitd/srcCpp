nclude <iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class phone
    {
        public:
        int id;
        double rear;
        double front;
        double speed;
        int RAM;
        int ROM;
        int battery;
        double score;
        phone()
            {
            score=0.0;
        }
    
};

double returnSpeed(string processor)
    {
        bool Xseen=false;
        string cores="",coreSpeed="";
    
        for (int i=0;i<processor.length();i++)
            {
                if (i==0)
                    cores+=processor[i];
            
                else
                    {
                        coreSpeed+=processor[i];            
                }                   
        }
    return ((double)stoi(cores))*atof(coreSpeed.c_str());
}

bool sortRear(phone p1,phone p2)
    {
        return (p1.rear>p2.rear);
}

bool sortFront(phone p1,phone p2)
    {
    return (p1.front>p2.front);
}

bool sortSpeed(phone p1,phone p2)
{
     return (p1.speed>p2.speed);
}

bool sortRAM(phone p1,phone p2)
    {
        return (p1.RAM>p2.RAM);
}

bool sortROM(phone p1,phone p2)
    {
        return (p1.ROM>p2.ROM);
}

bool sortScore(phone p1,phone p2)
    {
        return (p1.score<p2.score);
}

vector<phone> getScores(vector<phone> phoneVector,int field)
    {
        int j=1;
        for (vector<phone>::iterator i=phoneVector.begin();i!=phoneVector.end();i++)
            {
                                    (*i).score+=field*j;
                                    j++;
             
        }
    return phoneVector;
}

vector<phone> generateScores(vector<phone> phoneVector)
    {
        sort(phoneVector.begin(),phoneVector.end(),sortRear);
        phoneVector=getScores(phoneVector,1);
        
        sort(phoneVector.begin(),phoneVector.end(),sortFront);
        phoneVector=getScores(phoneVector,2);
        
        sort(phoneVector.begin(),phoneVector.end(),sortSpeed);
        phoneVector=getScores(phoneVector,3);
    
        sort(phoneVector.begin(),phoneVector.end(),sortRAM);
        phoneVector=getScores(phoneVector,4);
    
        sort(phoneVector.begin(),phoneVector.end(),sortROM);
        phoneVector=getScores(phoneVector,5);
        
        return phoneVector;
        
}



int main() {
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,K;
    cin>>N>>K;
    
    vector<phone> phoneVector;
    phone phoneVar;
    string processor;
    
    int i,j;
    
    for (i=1;i<=N;i++)
        {
            phoneVar.id=i;
            cin>>phoneVar.battery>>processor>>phoneVar.RAM>>phoneVar.ROM>>phoneVar.rear>>phoneVar.front;
            phoneVar.speed=returnSpeed(processor);
            phoneVector.push_back(phoneVar);
    }
    
    phoneVector=generateScores(phoneVector);
    
    sort(phoneVector.begin(),phoneVector.end(),sortScore);
    
    
    for (int j=0;j<K;j++)
     {
        cout<<phoneVector[j].id<<endl;
    }
    
return 0;
}
