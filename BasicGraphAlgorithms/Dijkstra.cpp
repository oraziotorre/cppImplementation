#include <iostream>
#include <queue>
#define MAXN 10001
#define MAXM 1000001
using namespace std;


int main(){
	
	
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int N,M;
	cin>>N>>M;
	
	int a,b;	
	cin>>a>>b;
	priority_queue<pair<int,int>> mind;
	a--;
	b--;

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
	
	
	bool Vis[MAXN];
	for(i=0;i<N;i++)
	{	
		Vis[i]=false;
		Dis[i]=99999999999;
	}
	
	Dis[a]=0;
	mind.push(make_pair(Dis[a],a));
	
	int k;		
	while(!mind.empty())
	{
		k=mind.top().second;
		mind.pop();
		Vis[k]=true;
		if(Vis[b])
			break;

		for(auto j:graf[k])	
				if(Vis[j.first]==false)					
					if(Dis[j.first]>Dis[k]+j.second)
					{
						Dis[j.first]=Dis[k]+j.second;
						mind.push(make_pair(-Dis[j.first],j.first));
					}
	}
	
	cout<<Dis[b]<<endl;
}
