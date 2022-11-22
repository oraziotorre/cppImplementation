#include <bits/stdc++.h>

using namespace std;


int main(){
	
	int n=3;

	vector<int> permutation(n);
	iota(permutation.begin(),permutation.end(),0);
	
	do {
		cout<<endl;
		for(int i:permutation)
			cout<<i<<" ";
	} while (next_permutation(permutation.begin(),permutation.end()));
	
}
