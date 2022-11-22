#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
#define MAXM 100000

using namespace std;
vector<int> graf[MAXM];
priority_queue<pair<int,pair<int,int>>> S;
int N, M, i;
int nodi;
bool V[MAXM];


void DFS(int x){
	int i;
	if(V[x]) return;
	
	V[x] = 1;
	++nodi;
	
	for(i=0;i<graf[x].size();i++){
		if(V[graf[x][i]]!=true){
			DFS(graf[x][i]);
		}
	}
}



void solve(){
	
	for(i=0;i<N;i++)
		V[i]=false;
	
	V[S.top().second.first]=true;
	V[S.top().second.second]=true;
	nodi=2;
	S.pop();
	
	while(!S.empty())
	{
		if(V[S.top().second.first]==false&&V[S.top().second.second]==false){
			graf[S.top().second.first].push_back(S.top().second.second);
			graf[S.top().second.second].push_back(S.top().second.first);
		}else
			if(V[S.top().second.first]==true||V[S.top().second.second]==true)
			{
				DFS(S.top().second.first);
				DFS(S.top().second.second);
			}
		if(nodi==N)
			break;
		S.pop();
	}
	cout<<S.top().first;	
}


int main() {

    assert(2 == scanf("%d %d", &N, &M));
    
    int a,b,c;
    
    for(i=0; i<M; i++)
        {
    		cin>>a>>b>>c;
			S.push(make_pair(c,make_pair(a,b)));
		}
		
	solve();

    return 0;
}