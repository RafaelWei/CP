#include<bits/stdc++.h>
using namespace std;

int N, n;
char bigger[500][500]; 
char smaller[500][500];

//rotate matrix inplace (pretty annoying)
void rotateMatrix(){
	for(int x=0; x<n/2; x++){
		for(int y=x; y<n-x-1; y++){
			int temp = smaller[x][y];

			smaller[x][y] = smaller[n-1-y][x];
			smaller[n-1-y][x] = smaller[n-1-x][n-1-y];
			smaller[n-1-x][n-1-y] = smaller[y][n-1-x];
			smaller[y][n-1-x] = temp;
		}
	}
}

void rotateMatrixExtra(){
	char temp[500][500];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			temp[i][j] = smaller[n-j-1][i];
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			smaller[i][j] = temp[i][j];
		}
	}
}

void checkMatrix(int N, int n){
	int ans= 0;
	for(int i=0; i<=N-n; i++){
		for(int j=0; j<=N-n; j++){
			int cnt = 0;
			for(int k=i; k<i+n; k++){
				for(int l=j; l<j+n; l++){
					if(bigger[k][l] == smaller[k-i][l-j]) cnt++;
				}
			}
			if(cnt == n*n) ans++;
		}
	}
	printf("%d", ans);
}

void solve(){
	for(int i=0; i<N; i++){
		scanf("%s", bigger[i]);
	}

	for(int i=0; i<n; i++){
		scanf("%s", smaller[i]);
	}

	checkMatrix(N, n);
	printf(" ");

	for(int i=0; i<3; i++){
		if(i<2){
			rotateMatrix();
			checkMatrix(N, n);
			printf(" ");
		}
		else{
			rotateMatrix();
			checkMatrix(N, n);
			printf("\n");
		}
	}

}

int main(){
	while(scanf("%d %d", &N, &n) && (N!=0 && n!=0)){
		solve();
	}
	return 0;
}