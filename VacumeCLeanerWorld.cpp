#include<iostream>
#include<string>
#include<vector>
using namespace std;
string rule(string x,string y);
struct record
{
	string state,percept,action;
	record()
	{
	}
	record(string state,string percept,string action)
	{
		this->percept=percept;
		this->state=state;
		this->action=action;
	}
};
vector<record>v;
int main()
{
	v.push_back(record("A","Clean","Right"));
	v.push_back(record("A","Dirty","Clean"));
	v.push_back(record("B","Clean","Left"));
	v.push_back(record("B","Dirty","Clean"));
	string x,y;
	while(cin>>x>>y)
	{
		cout<<rule(x,y)<<"\n";
	}


}

string rule(string x,string y)
{
	int i;
	for( i=0;i<v.size();i++)
	{
		if(x==v[i].state && y==v[i].percept)
		{
			break;
		}
	}
	return v[i].action;
}
