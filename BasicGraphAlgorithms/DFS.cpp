#include <bits/stdc++.h>

using namespace std;

vector<int> graf[4];

void dfs(int k, vector<bool> &Visitato){
	
	if(Visitato[k]) return;
	
	Visitato[k]=true;
	
	for(auto x:graf[k])
		dfs(x,Visitato);
		
}



int main(){
	
	//fornisce un controllo ma non le distanze
	
	graf[0].push_back(1);
	graf[1].push_back(3);
	graf[3].push_back(0);
	
	vector<bool> Visitato(4,false);
	dfs(0,Visitato);
	
	for(int i=0;i<4;i++)
	{
		if(!Visitato[i])
			cout<<i<<endl;
		
	}
	
	
}
