#include <bits/stdc++.h>

using namespace std;

const int Inf=999999;

int main(){
	
	//fornisce un controllo e la distanza(grafo non pesato)
	
	queue<int> q;
	
	vector<int> graf[4];
	
	graf[0].push_back(1);
	graf[1].push_back(3);
	graf[3].push_back(0);
	
	vector<bool> Visitato(4,false);
	vector<int> Distanza(4,Inf);
	Distanza[0]=0;
	q.push(0);
	Visitato[0]=true;
	
	while(!q.empty()){
		
		auto s=q.front();
		q.pop();
		
		for(auto x:graf[s])
			if(!Visitato[x])
				{
					Visitato[x]=true;
					Distanza[x]=Distanza[s]+1;
					q.push(x);
				}	
		
	}
	
	
	for(auto i:Distanza)
		cout<<i<<endl;
		
	
	
}
