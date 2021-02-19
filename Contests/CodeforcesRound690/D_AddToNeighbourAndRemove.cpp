// Greedy - the sum of the values in the array does not change.
/* 
A ideia eh usar invariantes.Como a soma dos elementos do array nao varia, vamos somando
elementos consecutivos ate ter a soma desejada de acordo com a qtd de grupos nos quais
os elementos iniciais devem ser divididos
*/

#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void solve(){
	int n, sum=0;
	scanf("%d", &n);
	
	vi vec(n);
	for(int &x:vec){
		scanf("%d", &x);
		sum+=x;
	}

	for (int i=n;i>=1;--i){
		if(sum%i==0){
			int needSum = sum/i;
			int currSum = 0;
			bool ok = true;
			for(int j=0; j<n; j++){
				currSum+=vec[j];
				if(currSum > needSum){
					ok=false;
					break;
				}
				else if(currSum==needSum){
					currSum = 0;
				}
			}
			if(ok){
				printf("%d\n", n-i);
				return;
			}
		}
	}

}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		solve();
	}
	return 0;
}