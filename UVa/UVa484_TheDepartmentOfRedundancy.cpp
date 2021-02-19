#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> seq;
	unordered_map<int, int> umap;
	int temp;
	while(cin >> temp){
		if(umap.find(temp)==umap.end()){
			seq.push_back(temp);
			umap[temp]++;
		}
		else umap[temp]++;
	}
	for(int i=0; i<seq.size(); i++){
		cout << seq[i] << " " << umap[seq[i]] << "\n";
	}
	return 0;
}