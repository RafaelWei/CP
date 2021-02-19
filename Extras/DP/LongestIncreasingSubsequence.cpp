//Longest increasing subsequence
#define MAX_SIZE 8

#include<bits/stdc++.h>
using namespace std;

int main(){
	int A[] = {-7, 10, 9, 2, 3, 8, 8, 1};
	int LIS[MAX_SIZE] = {1};
	for(int i=1; i<MAX_SIZE; i++){
		for(int j=0;j<i;j++){
			if(A[j]<A[i]) LIS[i] = max(LIS[i], LIS[j]+1);
		}
	}

	int ans=0;
	for(int i=0; i<MAX_SIZE; i++){
		if(LIS[i]>ans) ans = LIS[i];
	}

	printf("%d\n", ans);

	return 0;
}