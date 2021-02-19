#include<bits/stdc++.h>

using namespace std;

string cat[22];
int W[22], P[22];

int main(){
	int t, n;
	string word, line;
	cin >> t;
	while(t--){
		map<string, int> m[30];
		cin >> n;
		for(int i=0; i<n; ++i){
			cin >> cat[i] >> W[i] >> P[i];
			for(int j=0; j<W[i]; j++){
				cin >> word;
				m[i][word] = 0;
			}
		}
		cin.ignore(256, '\n');
		while(getline(cin, line)){
			if(line=="") break;
			int i;
			for(i=0; i<line.length(); ++i){
				if(isalpha(line[i])){
					char buf[100];
					int idx=0;
					while(isalpha(line[i])){
						buf[idx++] = line[i++];
					}
					buf[idx]='\0';
					for(int j=0; j<n; ++j){
						if(m[j].find(buf) != m[j].end()) m[j][buf] = 1;
					}
				}
			}
		}
		bool isSQF=true;
		for(int j=0; j<n; j++){
			int cnt=0;
			for(auto it=m[j].begin(); it!=m[j].end(); it++){
				cnt+=it->second;
			}
			if(cnt>=P[j]){
				if(isSQF){
					isSQF=false;
					cout<<cat[j];
				}
				else{
					cout<<","<<cat[j];
				}
			}
		}
		if(isSQF) cout << "SQF Problem.";
		cout << "\n";
	}
	
	return 0;
}