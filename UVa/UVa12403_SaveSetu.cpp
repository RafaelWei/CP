#include<bits/stdc++.h>

using namespace std;

int main(){
	string str; 
	int donate, n, total=0;

	cin >> n;
	while(n--){
		cin >> str;
		if(str == "donate"){
			cin >> donate;
			total+=donate;
		}
		else{
			cout << total << "\n";
		}
	}

	return 0;
}