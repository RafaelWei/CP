#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	bool firstCase = true;
	while(scanf("%d", &n) && n!=0){
		if(!firstCase) printf("\n");
		else firstCase = false;
		bool foundSol = false;
		for(int fghij=1234; fghij<=98765/n; ++fghij){
			int abcde = fghij * n;
			int temp, used = (fghij < 10000);
			temp = abcde; while(temp){used |= 1<<(temp%10); temp/=10;}
			temp = fghij; while(temp){used |= 1<<(temp%10); temp/=10;}
			if(used == (1<<10)-1){
				foundSol = true;
				printf("%.5d / %.5d = %d\n", abcde, fghij, n);
			}
		}
		if(!foundSol) printf("There are no solutions for %d.\n", n);
	}
	return 0;
}