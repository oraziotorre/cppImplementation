#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000001
#define MAXM 1000001





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
	tuple<int, int, int> graf[MAXN];	
	
	for(i=0;i<M;i++)
		{
			cin>>x>>y>>p;
			x--;
			y--;
			graf[i]=make_tuple(x,y,p);
		}



	for (i = 0; i <N; i++) 
		Dis[i] = 99999999999;
	
	Dis[start] = 0;
		
	for (i = 0; i <N; i++) 
		for (auto e:graf) {
			int a, b, w;
			tie(a,b,w)=e;
			Dis[b] = min(Dis[b], Dis[a]+w);
		}

	
	cout<<Dis[end]<<endl;
	
}
