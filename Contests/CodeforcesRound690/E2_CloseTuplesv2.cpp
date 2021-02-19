#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 300500;
const int mod = 1000000007;

ll fact[N];
ll invFact[N];

ll fastExp(ll a, ll n){
	ll ans = 1;
	while(n){
		if(n%2==0){
			a = (a*a) % mod;
			n/=2;
		}
		else{
			ans = ans*a %mod;
			n--;
		}
	}
	return ans;
}

ll comb(int n, int k){
	if(k>n) return 0;
	else return fact[n] * invFact[k] % mod * invFact[n-k] % mod;
}

void solve(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<ll> vec(n);
	for(ll &x:vec){
		scanf("%lld", &x);
	}
	sort(vec.begin(), vec.end());
	ll ans=0;
	for(int i=0; i<n; i++){
		int l = i+1;
		int r = upper_bound(vec.begin(), vec.end(), vec[i] + k) - vec.begin();
		ans = (ans + comb(r-l, m-1))%mod;
	}
	printf("%lld\n", ans);
}

int main(){
	fact[0] = invFact[0] = 1;
	for(int i=1; i<N; i++){
		fact[i] = (fact[i-1]*i)%mod;
		invFact[i] = fastExp(fact[i], mod-2);
	}
	int t;
	scanf("%d", &t);
	while(t--){
		solve();
	}
	return 0;
}