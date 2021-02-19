#include<bits/stdc++.h>
using namespace std;

int mat[8][8];

int main(){
	int t, n;
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				scanf("%d", &mat[i][j]);
			}
		}
		int permutation[] = {0, 1, 2, 3, 4, 5, 6, 7};
		int minimum = 10000;
		do{
			int sum = 0;
			for(int i=0; i<n; i++){
				sum+=mat[i][permutation[i]];
			}
			minimum = min(minimum, sum);
		}while(next_permutation(permutation, permutation+n));

		printf("%d\n", minimum);
	}
	return 0;
}