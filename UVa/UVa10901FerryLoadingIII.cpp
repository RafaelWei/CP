#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pi;

int cars[10005];

int main(){
	int c, n, t, m, aux;
	string buf;
	cin >> c;
	while(c--){
		queue<pi> leftBank, rightBank;
		bool atLeftBank = true;
		cin >> n >> t >> m;
		int time=0;
		for(int i=0; i<m; ++i){
			cin >> aux >> buf;
			if(buf[0] == 'l') leftBank.push(make_pair(aux, i));
			else rightBank.push(make_pair(aux, i));
		}
		while(!(leftBank.empty() && rightBank.empty())){
			int cnt=0;			
			if(leftBank.empty()){
				while(time<rightBank.front().first) time++;
			}
			else if(rightBank.empty()){
				while(time<leftBank.front().first) time++;
			}
			else{
				while(time<leftBank.front().first && time<rightBank.front().first){
					time++;
				}
			}
			
			if(atLeftBank){
				while(!leftBank.empty() && time>=leftBank.front().first && cnt<n){
					cars[leftBank.front().second]=time+10;
					cnt++;
					leftBank.pop();
				}
				time+=t;
				atLeftBank = false;
			}
			else{
				while(!rightBank.empty() && time>=rightBank.front().first && cnt<n){
					cars[rightBank.front().second]=time+10;
					cnt++;
					rightBank.pop();
				}
				time+=t;
				atLeftBank = true;
			}
		}
		for(int i=0; i<m; ++i){
			cout << cars[i] << "\n";
		}
		if(c>0) cout << "\n";
	}

	return 0;
}