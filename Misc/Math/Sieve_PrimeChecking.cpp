//Sieve of Erathostenes and prime checking

#include<bitset>
#include<vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound){
	_sieve_size = upperbound+1;
	bs.set();                         //setting all bits to 1
	bs[0] = bs[1] = 0;
	for(ll i=2; i<=_sieve_size; i++) if(bs[i]){
		for(ll j=i*i; j<=_sieve_size; j+=i){
			bs[j]=0;
		}
		primes.push_back((int)i);
	}
}

bool isPrime(ll n){
	if(n <= _sieve_size) return bs[n];
	for(int i=0; i<primes.size(); i++){
		if(n%primes[i]==0) return false;
	}
	return true;
}

int main(){
	sieve(10000000);
	printf("%d\n", isPrime(7));
	printf("%d\n", isPrime(1234567));
	return 0;
}