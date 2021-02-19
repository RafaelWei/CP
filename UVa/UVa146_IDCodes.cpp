#include<bits/stdc++.h>
using namespace std;

int main(){
	char str[55];

	while(scanf("%s", str) && str[0]!='#'){
		int cnt=0;
		while(str[cnt]!='\0'){
			cnt++;
		}
		if(next_permutation(str, str+cnt)){
			puts(str);
		}
		else{
			printf("No Successor\n");
		}
	}
	return 0;
}