#include <iostream>
#include <vector>
#define MAXN 101				//valori grandi fanno crashare il programma
#define MAXM 101
using namespace std;

long long Infinite=99999999999;

int main(){
	


	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int N,M;
	cin>>N>>M;
	
	int a,b;	
	cin>>a>>b;
	
	a--;
	b--;
		
	long long Dis[MAXN][MAXN];
	int Next[MAXN][MAXN];
	int i,j;
	int x,y,z;
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			Dis[i][j]=Infinite;
			Next[i][j]=-1;
		}
		Dis[i][i]=0;
		Next[i][i]=i;
	}
	
	for(int i=0;i<M;i++)
		{
			cin>>x>>y>>z;
			x--;
			y--;
			Dis[x][y]=z;
			Next[x][y]=x;
		}
	

	for(int h=0;h<N;h++)
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				if(Dis[i][j]>Dis[i][h]+Dis[h][j])
				{
					Dis[i][j]=Dis[i][h]+Dis[h][j];
					Next[i][j]=Next[h][j];
					}
	
	
	cout<<Dis[a][b]<<endl;
}



