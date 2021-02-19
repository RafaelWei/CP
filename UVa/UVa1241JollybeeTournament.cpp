#include<bits/stdc++.h>

using namespace std;

int main(){
	int t, n, m, aux;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		int nums = pow(2,n);
		int ans=0;
		bitset<1024> bits;
		bits.set();
		while(m--){
			scanf("%d", &aux);
			bits.reset(aux-1);
		}
		while(nums){
			int idx=0;
			for(int i=1; i<nums; i+=2){
				ans = bits.test(i) ^ bits.test(i-1);
				bits[idx++] = bits.test(i) | bits.test(i-1);
			}
			nums >>= 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}