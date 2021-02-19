#include<bits/stdc++.h>
using namespace std;

int seq[10001];

int main(){
	int n;
	int cnt=0;
	while(scanf("%d", &n)!=EOF){
		seq[cnt++]=n;
		sort(seq, seq+cnt);
		if(cnt%2==1){
			printf("%d\n", seq[cnt/2]);
		}
		else{
			long long median = (seq[cnt/2]+ seq[cnt/2-1])/2;
			printf("%lld\n", median);
		}
	}
	return 0;
}