#include<bits/stdc++.h>
using namespace std;

int A[301];

int main(){
	int t, n;
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);
		int p1=0, p2=n-1, par=1;
		for(int i=0; i<n; i++){
			scanf("%d", &A[i]);
		}
		while(p1!=p2){
			if(par) {printf("%d ", A[p1++]); par=0;}
			else {printf("%d ", A[p2--]); par=1;}
		}
		printf("%d\n", A[p1]);
	}

	return 0;
}