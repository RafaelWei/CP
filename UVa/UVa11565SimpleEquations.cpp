#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, a, b, c;
	scanf("%d", &n);
	while(n--){
		bool foundSol = false;
		scanf("%d %d %d", &a, &b, &c);
		for(int x=-100; x<100; ++x){
			for(int y=-100; y<100; ++y){
				for(int z=-100; z<100; ++z){
					if(x!=y && x!=z && y!=z && x+y+z==a && x*y*z==b && x*x+y*y+z*z==c){
						if(!foundSol) {printf("%d %d %d\n", x, y, z); foundSol=true; break;}
					}
				}
				if(foundSol) break;
			}
			if(foundSol) break;
		}
		if(!foundSol) printf("No solution.\n");
	}
	return 0;
}