#include<bits/stdc++.h>

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		int ans=0;
		for(int i=0; i<4; i++){
			int origin = i*8;
			int dest = (3-i)*8;
			for(int j=0; j<8; j++){
				if(n & 1<<(origin+j)){
					ans |= 1<<(dest+j);
				}
			}
		}
		printf("%d converts to %d\n", n, ans);
	}
	return 0;
}