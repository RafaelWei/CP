#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	string str;

	cin >> n;
	cin >> str;
	for(int i=0; i<=4; i++){
		if(str.substr(0, i) + str.substr(n-4+i, 4-i) == "2020"){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main(){
	int t;

	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}