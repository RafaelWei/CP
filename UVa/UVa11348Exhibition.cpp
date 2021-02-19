#include<bits/stdc++.h>

using namespace std;

int main(){
	int k,n, qtd, aux;
	scanf("%d", &k);
	for(int i=1; i<=k; ++i){
		int total=0;
		map<int, int> m[55];
		double friends[55] = {0};
		scanf("%d", &n);
		for(int j=1; j<=n; ++j){
			scanf("%d", &qtd);
			for(int k=0; k<qtd; ++k){
				scanf("%d", &aux);
				m[0][aux]++;
				m[j][aux]++;
			}
		}
		for(auto& element:m[0]){
			if(element.second == 1){
				int stamp = element.first;
				total++;
				for(int j=1; j<=n; ++j){
					if(m[j].find(stamp) != m[j].end()){
						friends[j] += 1;
					}
				}
			}
		}
		for(int j=1; j<=n; j++){
			if(total!=0){
				friends[j] = friends[j]/total;
			}
		}
		printf("Case %d:", i);
		for(int j=1; j<=n; ++j){
			printf(" %.6lf%%", 100*friends[j]);
		}
		printf("\n");
	}
	return 0;
}