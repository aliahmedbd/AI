#include<iostream>
#include <fstream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
vector<vector<int>>G;


class Graph{
	

	int V,E,x,y;

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
	
	void bfs(int src,int des)
{
	
	queue<int>Q;
	queue<int>Q1;
	Q.push(src);
	int visited[100];
	int level[100];
	int parent[100];
	int u,v;
	visited[src]=1;
	level[src]=0;
	
	
	
	for(int i=0;i<100;i++){
		visited[i]=0;
		level[i]=0;
	}
	visited[src]=1;
	level[src]=0;
	int counter=0;

	while(!Q.empty())
	{		
		u=Q.front();	
		for(int i=0;i<G[u].size();i++)
		{
			v=G[u][i];
			if(!visited[v])
			{
				level[v]=level[u]+1;
				parent[v]=u;
				visited[v]=1;
				Q.push(v);

			}			
		}
		Q.pop();
	}
	for(int i=1;i<=des;i++)
		printf("%d to %d distance %d\n",src,i,level[i]);
}

	
	


};
int main(){
	Graph G("input.txt");
	
	//G.output();
	int s,d;
	while(cin >> s >> d){
		G.bfs(s,d);
	}
}

