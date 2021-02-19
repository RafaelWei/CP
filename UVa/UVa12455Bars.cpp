#include<bits/stdc++.h>

using namespace std;

int bars[22];

int main(){
	int t, n, p;
	scanf("%d", &t);
	while(t--){
		bool foundSol = false;
		scanf("%d", &n);
		scanf("%d", &p);
		for(int i=0; i<p; ++i){
			scanf("%d", &bars[i]);
		}
		for(int i=0; i<(1<<p); ++i){
			int sum=0;
			for(int j=0; j<p; ++j){
				if(i & (1<<j)) sum+=bars[j];
			}
			if(sum==n) {foundSol=true; break;}
		}
		if(foundSol) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}