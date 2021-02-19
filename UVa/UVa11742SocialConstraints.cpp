#include<bits/stdc++.h>

using namespace std;

int a[22], b[22], c[22];
int main(){
	int n, m;
	while(scanf("%d %d", &n, &m) && n+m){
		for(int i=0; i<m; ++i){
			scanf("%d %d %d", &a[i], &b[i], &c[i]);
		}
		int p[8] = {0, 1, 2, 3, 4, 5, 6, 7};
		int cnt=0;
		do{
			bool ok = true;
			for(int i=0; i<m; ++i){
				int posA, posB, dist;
				for(int j=0; j<n; ++j){
					if(p[j] == a[i]) posA = j;
					if(p[j] == b[i]) posB = j;
				}
				dist = abs(posA-posB);
				if(c[i] > 0){
					if(dist > c[i]) {ok = false; break;}
				}
				else{
					if(dist < -c[i]) {ok = false; break;}
				}
			}
			if(ok) cnt++;
		}while(next_permutation(p, p+n));

		printf("%d\n", cnt);
	}
	return 0;
}