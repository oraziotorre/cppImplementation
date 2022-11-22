#include <bits/stdc++.h>
using namespace std;

vector<pair<int,long long>> graf[500000];	

void brucia(int N, vector<int> &M, vector<int> &B, vector<long long> &T){
	
	vector<int> Pos(N);
	
	for(int i=0;i<N;i++)
		T[i]=-1;
	

	
    iota(Pos.begin(), Pos.end(), 0);
    sort(Pos.begin(), Pos.end(), [&](int a, int b) { return M[a] < M[b]; });

	
/*	for(int i=0;i<N;i++)
		for(int j=i;j<N;j++)
			if(M[Pos[i]]>M[Pos[j]])
			{
				if(k==i)
					k=j;
				else
					if(k==j)
						k=i;
				app=Pos[i];			
				Pos[i]=Pos[j];
				Pos[j]=app;				
			}
*/			
			
		
	


	stack<int> stk;

	for(int i=0;i<N;i++){
	
		while(!stk.empty() && B[stk.top()] < M[Pos[i]]){
			
			stk.pop();
			
		}
		
		if (!stk.empty()) 
            graf[stk.top()].emplace_back(Pos[i],M[Pos[i]] - M[stk.top()]);
        
		if (M[Pos[i]] < B[Pos[i]]){
            while (!stk.empty() && B[stk.top()] <= B[Pos[i]]) 
                stk.pop();
            stk.push(Pos[i]);
        }
		
	}		
	reverse(Pos.begin(), Pos.end());
	

	while(!stk.empty())
   		stk.pop();
	
	for(int i=0;i<N;i++){
	
		while(!stk.empty() && B[stk.top()] > M[Pos[i]]){
			
			stk.pop();
			
		}
		
		if (!stk.empty()) 
            graf[stk.top()].emplace_back(Pos[i], M[stk.top()] - M[Pos[i]]);
        
		if (M[Pos[i]] > B[Pos[i]]){
            while (!stk.empty() && B[stk.top()] >= B[Pos[i]]) 
                stk.pop();
            stk.push(Pos[i]);
        }
		
	}
	
	

	
	vector<bool> V(N,false);
	priority_queue<pair<long long,int>> q;
	for (int i = 0; i < N; i++) {
        if (M[i] == M[0]) {
            T[i] = 0;
            q.emplace(0, i);
        }
    }

	
	while(!q.empty())
	{
		
		int ind=q.top().second;
		q.pop();
		V[ind]=true;
		
		
		for(int j=0;j<graf[ind].size();j++)
		{
			if(!V[graf[ind][j].first])
				if(T[graf[ind][j].first]==-1||T[graf[ind][j].first]>T[ind]+graf[ind][j].second)
				{
					T[graf[ind][j].first]=T[ind]+graf[ind][j].second;
					q.push(make_pair(-T[graf[ind][j].first],graf[ind][j].first));
					
				}
				
		}
		
	}
	
	
		
}
