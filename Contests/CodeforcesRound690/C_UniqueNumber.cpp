#include<bits/stdc++.h>
using namespace std;

int somaDigs(int n){
	int sum=0;
	while(n){
		sum+= n%10;
		n/=10;
	}
	return sum;
}

bool diffDigs(int n){
	int aux = 0;
	while(n){
		if(aux & (1<<n%10)!=0) return false;
		else aux |= (1<<n%10);
		n/=10;
	}
	return true;
}

int main(){
	int t, n;
	bool foundAns = false;
	scanf("%d", &t);

	for(int i=0; i<t; i++){
		scanf("%d", &n);
		if(n<=45){
			for(int j=0; j<=123456789; j++){
				if(somaDigs(j)==n && diffDigs(j)){
					printf("%d\n", j);
					foundAns = true;
					break;
				}
			}
			if(foundAns) foundAns=false;
			else printf("-1\n");
		}
		else{
			printf("-1\n");
		}
	}
	return 0;
}