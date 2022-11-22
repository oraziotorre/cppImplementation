#include <bits/stdc++.h>

using namespace std;

int range(int a,int b,int N,vector<int> &Segm){
	
	a=a+N;
	b=b+N;
	int minimo=99999;
	
	while(a<=b)
	{
		if(a%2==1)	
			minimo=min(minimo,Segm[a++]);
		
		if(b%2==0)	
			minimo=min(minimo,Segm[b--]);
		
		a=a/2;
		b=b/2;
	}
		
	return minimo;	
}


void modifica(int p,int x,int N,vector<int> &Segm){
	
	p=p+N;
	
	Segm[p]=x;
	
	for(p=p/2;p>0;p=p/2)
		Segm[p]=min(Segm[p*2],Segm[(p*2)+1]);	
	
	
}



int main(){
	
	int N;
	
	cin>>N;	//Inserisci numero elementi
	
	int N2=1;
	
	if((N&(N-1))!=0)		//Grandezza array deve essere una potenza di 2	
		while(N2<N)
			N2=N2<<1;		
	else
		N2=N;
	
	vector<int> Segm(N2*2,9999999);
	
	for(int i=N2;i<N2+N;i++)
		cin>>Segm[i];
	
	for(int i=(N2*2)-1;i>0;i=i-2)   //Creo il segment tree
		Segm[i/2]=min(Segm[i],Segm[i-1]);

		
	int a,b;
	a=0;
	b=3;
	int minrange=range(a,b,N2,Segm); //Dato il range a b ti restituisce il valore minimo
	cout<<minrange<<endl;
	
	int posizione=3;
	int nuovovalore=-1;
	
	modifica(posizione,nuovovalore,N2,Segm); //aggiorna il segment tree con il numero valore nella posizione data
	
	minrange=range(a,b,N2,Segm);
	cout<<minrange<<endl;
	
}
