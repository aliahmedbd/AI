
#include<iostream>
#include <fstream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
vector<vector<int>>G;


class Graph{
	

	int V,E,x,y;
	string color[100];
	int time;
	int distance[100];
	int parent[100];

public :
	Graph ( string filename ) 
	{
		input(filename) ;
	}

	void input( string filename ) 
	{
		 ifstream myfile;
		 myfile.open(filename) ;

		 myfile >> V >> E ;
		 G.resize( V +1 ) ;
		 int count = E ;
		 int src , dest ; 
		 while( count-- ) 
		 {
			 myfile >> src >> dest ;
			 G[src].push_back(dest) ;

		 }
	}
	void DFS(){
		for(int i=1;i<=V;i++){
			color[i]="WHITE";
		}
		time=0;
		for(int i=1;i<=V;i++){
			if(color[i]=="WHITE"){
				DFS_visit(i);
			}
		}

	}
	void DFS_visit(int u){
		color[u]="GREY";
		time=time+1;
		distance[u]=time;
		for(int i=0;i<G[u].size();i++){
			if(color[i]=="WHITE"){
				parent[i]=G[u][i];
				cout << parent[i] << endl;
				DFS_visit(i);

			}
			color[u]="BLACK";
			time=time+1;
		}



	}
	
};
int main(){
	Graph G("input.txt");
	
	//G.output();
	int s,d;
	G.DFS();
}
