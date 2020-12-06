#include<bits/stdc++.h>

using namespace std;

int main(){
	int T, N, big, small, cnt=1;
	int walls[50];

	scanf("%d", &T);
	while(T--){
		big = small = 0;
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			scanf("%d", &walls[i]);
		}
		for(int i=1; i<N; i++){
			if(walls[i] > walls[i-1]) big++;
			if(walls[i] < walls[i-1]) small++;
		}
		printf("Case %d: %d %d\n", cnt++, big, small);
	}
	return 0;
}