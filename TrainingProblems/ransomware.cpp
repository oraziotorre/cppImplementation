#include <iostream>

using namespace std;

int main(){
	int i;
	int N; int k;
	cin>>N;
	string V[1000];
	string Vet[100];
	string z;
	int m=0;
	
	for(i=0;i<N;i++)
		cin>>V[i];		
	for(i=0;i<10;i++)
		cin>>Vet[i];

	for(i=0;i<N;i++)
	 {m=0;
	 	while(m!=V[i].length())
	 	{
	    	z.replace(0,V[i].length(),V[i],m,V[i].length());
	 //	cout<<" (  "<<z<<"   )"<<endl;
	    	for(k=0;k<10;k++)
	 	    	if(Vet[k]==z.substr(0,Vet[k].length()))
	 			{
		    		 m=m+Vet[k].length();
		    		 cout<<k;
				 }
        }
    cout<<endl;
	     
	 }
}