//count the number of primes

#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

vi primes;
ll _sieve_size;
bitset<10000010> bs;

void sieve(ll upperbound){
	_sieve_size = upperbound+1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i=0; i<=_sieve_size; i++) if(bs[i]){
		for(ll j=i*i; j<=_sieve_size; j+=i){
			bs[j]=0;
		}
		primes.push_back(i);
	}
}

int countPrimes(ll n){
	int index=0, PF=primes[index];
	int cnt=0;
	while(PF*PF <= n){
		while(n%PF==0){
			n/=PF;
			cnt++;
		}
		PF = primes[++index];
	}
	if(n!=1) cnt++;
	return cnt;
}

int main(){
	sieve(1000000);

	printf("%d\n", countPrimes(142391208960LL));
	
	return 0;
}