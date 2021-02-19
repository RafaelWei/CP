#include<bits/stdc++.h>

using namespace std;

const int MAXTIME = 1000000;
bitset<MAXTIME> bits;

int main(){
	int n, m, start, end, rep;
	while(scanf("%d %d", &n, &m) && n+m!=0){
		bits.reset();
		bool valid = true;
		while(n--){
			scanf("%d %d", &start, &end);
			for(int i=start; i<end; i++){
				if(bits.test(i)){
					valid = false;
				}
				bits.set(i);
			}
		}
		while(m--){
			scanf("%d %d %d", &start, &end, &rep);
			while(valid && start<MAXTIME){
				for(int i=start; i<end; i++){
					if(bits.test(i)){
						valid = false;
					}
					bits.set(i);
				}
				start += rep;
				end = min(end+rep, MAXTIME);
			}
		}
		if(valid) printf("NO CONFLICT\n");
		else printf("CONFLICT\n");
	}
}