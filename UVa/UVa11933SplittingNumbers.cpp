#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while(scanf("%d", &n) && n!=0){
		int a=0, b=0;
		bool odd = true;
		for(int i=0; i<32; i++){
			if(n & (1<<i)){
				if(odd){
					a |= 1<<i;
				}
				else{
					b |= 1<<i;
				}
				odd = !odd;
			}
		}

		printf("%d %d\n", a, b);
	}

	return 0;
}