#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<fstream>

using namespace std;

class A {
public:
	vector<int>G[100];
	int node,edges;
	
	void input(){
		 ifstream myfile;
		 myfile.open("input.txt") ;

		int a , b ;
		myfile >> node >> edges;
		//G.resize(node+1);
		for(int i=1;i<=node;i++){
			G[i].resize(node+1);
			//cout<<i<<" "<<G[i].size()<<"\n";
		}
		this->initialize();

		for( int i = 1 ; i <=edges ; i ++ ) 
		{
			 myfile>>a>>b;
			 G[a][b]=1;
		}

	}
	void output(){
		for(int i=1;i<=node;i++){
			for(int j=1;j<=node;j++){

				 cout<<G[i][j]<<"\t";
			}
			cout << endl<<endl;
		}
	}
	
	void initialize()
	{
		for(int i=1;i<=node;i++)
		{
			for(int j=1;j<=node;j++)
			{
				G[i][j]=0;
			}
		}
	}
	 
};
int main(){
	A ob=A();
	ob.input();
	//ob.initialize();
	ob.output();
	//ob.adjacancy();
	
	
}
