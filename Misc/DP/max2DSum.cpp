//Max 2D Range Sum
#include<bits/stdc++.h>
using namespace std;

/***************Naive Solution****************/
/*
O(n^6)
maxSubRect = -127*100*100
int mat[100][100];
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &mat[i][j]);
		}
	}

	for(int i=0; i<n; i++) for(int j=0;j<n;j++)
		for(int k=i; k<n; k++) for(int l=j; l<n; l++){
			subrect = 0;
			for(int a=i; a<=k; a++) for(int b=j; b<=l; b++)
				subrect += mat[a][b];
			maxSubRect = max(maxSubRect, subrect);
		}
	return 0;
}
*/

/************Smart Solution******************/
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) for(int j=0; j<n; j++){
		scanf("%d", &mat[i][j]);
		if(i>0) mat[i][j] += mat[i-1][j];
		if(j>0) mat[i][j] += mat[i][j-1];
		if(i>0 && j>0) mat[i][j] -= mat[i-1][j-1];
	}

	for(int i=0; i<n; i++) for(int j=0; j<n; j++)
		for(int k=i; k<n; k++) for(int l=0; l<n; l++){
			subrect = mat[k][l];
			if(i>0) subrect -= mat[i-1][l];
			if(j>0) subrect -= mat[k][j-1];
			if(i>0 && j>0) subrect += mat[i-1][j-1];
			maxSubRect = max(maxSubRect, subrect);
		}

	return 0;
}