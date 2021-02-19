#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll _sieve_size;
vi primes;
bitset<10000000> bs;

void sieve(ll upperbound){
	_sieve_size = upperbound+1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i=2; i<= _sieve_size; i++) if(bs[i]){
		for(ll j=i*i; j<=_sieve_size; j+=i){
			bs[j]=0;
		}
		primes.push_back(i);
	}
}

vi primeFactors(ll n){
	vi factors;
	ll index=0, PF=primes[index];
	while(PF * PF <= n){
		while(n%PF == 0){n/=PF; factors.push_back(PF);}
		PF = primes[++index];
	}
	if(n!=1) factors.push_back(n);
	return factors;
}

int main(){
	sieve(10000000);
	
	vi r = primeFactors(2147483647);            // slowest, 2147483647 is a prime
	for (vi::iterator i = r.begin(); i != r.end(); i++) printf("> %d\n", *i);
	r = primeFactors(136117223861LL);           // slow, 104729*1299709
	for (vi::iterator i = r.begin(); i != r.end(); i++) printf("# %d\n", *i);
	r = primeFactors(142391208960LL);           // faster, 2^10*3^4*5*7^4*11*13
	for (vi::iterator i = r.begin(); i != r.end(); i++) printf("! %d\n", *i);

	return 0;
}