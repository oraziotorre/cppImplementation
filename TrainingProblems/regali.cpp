#include <stdio.h>
#include <iostream>
#include <assert.h>

#define MAXN 10000
#define MAXQ 1000

int compra(int N, int Q, int* G[]) {
    
    int counter = 0, max = 0, incr = 1, i = 0;
	while(i < N){
        for (int j = 0; j < Q; j++){
        	if(i+incr<N)
            if (G[i][j] != G[i+incr][j]) {
            	incr++; j = -1; 
				if (counter > max) max = counter; counter = 0;
			}  
			else counter++; 
            if ( (i+incr) >= N ) {
            	i++; incr = 1;
			}
        }
    }
  
    return max;
}

int* G[MAXN];

int main() {
    FILE *fr, *fw;
    int N, Q, i, j;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &Q));
    for(i=0; i<N; i++) {
        G[i] = (int*)malloc(Q*sizeof(int));
        for (j=0; j<Q; j++) {
            assert(1 == fscanf(fr, "%d", &G[i][j]));
        }
    }

    fprintf(fw, "%d\n", compra(N, Q, G)); 
    fclose(fr);
    fclose(fw);
    return 0;
}	