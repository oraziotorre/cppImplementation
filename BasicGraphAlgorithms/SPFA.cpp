#include <bits/stdc++.h>

using namespace std;

#define MAXN 10001
#define MAXM 10001





int main(){
	
	
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int N,M;
	cin>>N>>M;
	
	int start,end;	
	cin>>start>>end;
	start--;
	end--;

	long long Dis[MAXN];
	int i;
	int x,y,p;
	vector<pair<int, int> > graf[MAXN];	
	
	for(i=0;i<M;i++)
		{
			cin>>x>>y>>p;
			x--;
			y--;
			graf[x].push_back(make_pair(y,p));
		}



	for (i = 0; i <N; i++) 
		Dis[i] = 99999999999;
	
	Dis[start] = 0;
	int k;	
	queue<int> mind;
	mind.push(start);
	
		
	while(!mind.empty())
	{
		k=mind.front();
		mind.pop();

		for(auto j:graf[k])					
			if(Dis[j.first]>Dis[k]+j.second)
					{
						Dis[j.first]=Dis[k]+j.second;
						mind.push(j.first);
					}	
	}
	
	
	cout<<Dis[end]<<endl;
}
