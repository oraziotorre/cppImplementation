#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int BFS(vector<vector<int>> &graf,int N){
	
	queue<int> q;
	vector<int> V(N*N,-1);
	V[0]=1;
	q.push(0);
	
	
	
	
	while(!q.empty())
	{
		for(int j=0;j<graf[q.front()].size();j++)
			if(V[graf[q.front()][j]]==-1)
				{
				V[graf[q.front()][j]]=V[q.front()]+1;
				q.push(graf[q.front()][j]);
				}
		q.pop();		
	}

	return(V[N*N-1]);
	
}






int main(){

	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


	int N;
	cin>>N;
	
	vector<vector<int>> G(N + 2, vector <int> (N + 2, -1));
	char c;
	int a=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			{
			cin>>c;
			if(c=='*')
				G[i][j]=a;
				
			a++;
			}		
	
	vector<vector<int>> graf(N*N);
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)			
			{
				if(G[i][j]!=-1){
				
					if(G[i][j+1]!=-1)
						{
						graf[G[i][j]].push_back(G[i][j+1]);
						graf[G[i][j+1]].push_back(G[i][j]);
				}
					if(G[i+1][j]!=-1)	
						{
						graf[G[i][j]].push_back(G[i+1][j]);
						graf[G[i+1][j]].push_back(G[i][j]);
				}
					if(G[i+1][j+1]!=-1)
						{
						graf[G[i][j]].push_back(G[i+1][j+1]);
						graf[G[i+1][j+1]].push_back(G[i][j]);
					}
				if((i!=0)&&(G[i-1][j+1]!=-1))
					{	
						graf[G[i][j]].push_back(G[i-1][j+1]);
						graf[G[i-1][j+1]].push_back(G[i][j]);
					}
					}
				}
	
	
	int b=BFS(graf,N);
	
	cout<<b;
	
	
	}
