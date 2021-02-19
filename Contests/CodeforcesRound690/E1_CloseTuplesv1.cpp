/*
Versao facil. Da pra calcular os valores na mao
*/
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

void solve(){
	int n;
	int ans=0;
	int temp;
	scanf("%d", &n);
	vi vec(n+1);

	for(int i=0; i<n; i++){
		scanf("%d", &temp);
		vec[temp]++;
	}

	for(int i=1; i<n-1; i++){
		ans+= vec[i]*vec[i+1]*vec[i+2];
	}
	for(int i=1; i<n; i++){
		ans+=vec[i]*vec[i+1]*(vec[i+1]-1)/2;
	}
	for(int i=1; i<n-1; i++){
		ans+=vec[i]*vec[i+2]*(vec[i+2]-1)/2;
	}
	for(int i=1; i<n; i++){
		ans+=vec[i]*(vec[i]-1)*vec[i+1]/2;
	}
	for(int i=1; i<n-1; i++){
		ans+=vec[i]*(vec[i]-1)*vec[i+2]/2;
	}
	for(int i=1; i<=n; i++){
		ans+=vec[i]*(vec[i]-1)*(vec[i]-2)/6;
	}

	printf("%d\n", ans);
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		solve();
	}
	return 0;
}