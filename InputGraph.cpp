#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<vector<int>>G;
queue<int>Q;

class BFS{
	
public:
	int node, edges, x, y;
	void input(){
		cin >> node >> edges;
		G.resize(node + 1);
		for (int i = 0; i < node; i++){
			cin >> x >> y;
			G[x].push_back(y);
		}
	}
	void output(){
		for (int i = 1; i <= node; i++){
			cout << i << "   ";
			for (int j = 0; j < G[i].size(); j++){
				cout << G[i].at(j) << "   ";
			}
			cout << endl;
		}
	}
	void bfs(int src,int des){
		Q.push(src);
		int visited[100], level[100], parent[100];
		for (int i = 0; i < 100; i++){
			visited[i] = 0;
			level[i] = 0;
		}
		visited[src] = 1;
		level[src] = 0;
		while (!Q.empty()){
			int u = Q.front();
			for (int i = 0; i < G[u].size(); i++){
				int v = G[u][i];
				if (!visited[v]){
					level[u] = level[u] + 1;
					parent[v] = u;
					visited[v] = 1;
					Q.push(v);

				}
			}
			Q.pop();

		}
		cout << src << " to " << des << "distance " << level[des] << endl;

	}

};
int main(){
	BFS ob;
	ob.input();
	ob.output();
	int s, d;
	while (cin >> s >> d){
		ob.bfs(s,d);
	}

}
