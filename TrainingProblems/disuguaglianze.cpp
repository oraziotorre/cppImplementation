#include <iostream>
#include <vector>
using namespace std;

int main(){
	
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	
	int N;
	cin>>N;
	
	vector<int> V(N);
	vector<char> a(N-1);
	
	for(int i=0;i<N-1;i++)
	{	cin>>a[i];
		V[i]=i+1;
	}
	V[N-1]=N;
	int App;
	bool b=true;
	
	while(b==true)
		{b=false;
		for(int i=0;i<N-1;i++)
		 {
		 	if(a[i]=='<')
		 		{
				 if(V[i]>V[i+1])
		 			{App=V[i];
		 			V[i]=V[i+1];
		 			V[i+1]=App;
		 			b=true;
					 }
			}else
				if(V[i]<V[i+1])
		 			{App=V[i];
		 			V[i]=V[i+1];
		 			V[i+1]=App;
		 			b=true;
					 }
	 }
	 	
	 }
	
	for(int i : V)
		cout<<i<<" ";
	
	
}