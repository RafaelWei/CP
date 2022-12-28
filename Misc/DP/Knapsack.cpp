// Knapsack problem 
#define N 4
#define S 12

#include<bits/stdc++.h>
using namespace std;

int memo[N+1][S+1];
int V[] = {100, 70, 50, 10};
int W[] = {10, 4, 6, 12};

int val(int id, int remW){
	if(remW==0 || id==N) return 0; 
	if(memo[id][remW]!=-1) return memo[id][remW];
	if(remW < W[id]) return val(id+1, remW);
	else return max(val(id+1, remW), val(id+1, remW-W[id]) + V[id]);
}

int main(){
	memset(memo, -1, sizeof memo);
	for(int i=0; i<N; i++) memo[i][0] = 0;
	for(int j=0; j<S; j++) memo[N-1][j] = 0;
	int ans = val(0, S);
	printf("%d\n", ans);
	return 0;
}