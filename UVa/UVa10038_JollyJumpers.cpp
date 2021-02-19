#include<bits/stdc++.h>
using namespace std;

int n;
int arr[3001];

void solve(){
	int temp[3001] = {0};
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	for(int i=0; i<n-1; i++){
		if(temp[abs(arr[i]-arr[i+1])]==0) temp[abs(arr[i]-arr[i+1])]=1;
		else {printf("Not jolly\n"); return;}
	}
	for(int i=1; i<n; i++){
		if(temp[i]==0){printf("Not jolly\n"); return;}
	}
	printf("Jolly\n");
}

int main(){
	while(scanf("%d", &n)==1){
		solve();
	}
}