#include<bits/stdc++.h>

using namespace std;

map<string, float> m;

int main(){
	int t, cnt=0;
	string name, blank;
	cin >> t;
	getline(cin, blank);
	getline(cin, blank);
	cout.precision(4);
	while(t--){
		while(getline(cin,name)){
			if(name=="") break;
			m[name]++;
			cnt++;
		}
		for(auto it = m.begin(); it!=m.end(); it++){
			cout << it->first << " " << fixed << 100*it->second/cnt << "\n";
		}
		if(t!=0){
			cout<<"\n";
		}
		m.clear();
		cnt=0;
	}
	return 0;
}