#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Knapsack
{
	int numObject;
	double maxWeight,valueObtained;

	struct object
	{
		int num;
		double weight,value,prop;
	};

	
	vector<object> Ob;
	
	static bool sortOb(object,object);
	void orderObjects();

	public:
	Knapsack(double maxWeight)
	{
		numObject=0;
		valueObtained=0.0;
		this->maxWeight=maxWeight;
	}
	
	void addObject(double,double);
	void fillKnapsack();
};

void Knapsack::addObject(double w,double v)
{
	object p;
	p.weight=w;
	p.value=v;
	p.prop=0.0;
	p.num=++numObject;
	Ob.push_back(p);
}

bool Knapsack::sortOb(object o1,object o2)
{
	return ((o1.value/o1.weight)>(o1.value/o2.weight));
}

void Knapsack::orderObjects()
{
	sort(Ob.begin(),Ob.end(),sortOb);
}

void Knapsack::fillKnapsack()
{
	orderObjects();

	double w=maxWeight;
	for (vector<object>::iterator i=Ob.begin();i!=Ob.end();i++)
	{
		if (i->weight<w)
		{
			i->prop=1.0;
			w-=i->weight;
			valueObtained+=i->value;
			cout<<"Object "<<i->num<<" Proportion="<<i->prop<<"\n";
		}
		
		else
		{
			i->prop=w/i->weight;
			valueObtained+=i->value*i->prop;
			cout<<"Object "<<i->num<<" Proportion="<<i->prop<<"\n";
			break;
		}
	}
	
	cout<<"Value Obtained = "<<valueObtained<<"\n";

}
		
int main()
{
	Knapsack k(15);
	k.addObject(2,10);
	k.addObject(3,5);
	k.addObject(5,15);
	k.addObject(7,7);
	k.addObject(1,6);
	k.addObject(4,18);
	k.addObject(1,3);
	k.fillKnapsack();
	return 0;
}	
