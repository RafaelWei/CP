#include<bits/stdc++.h>

using namespace std;

int main(){
	string line;
	while(getline(cin, line)){
		deque<string> beiju;
		int idx=0, i=0;
		bool insertAtEnd=true;
		char buf[100005];
		for(i=0; i<line.length(); ++i){
			while(line[i]!='[' && line[i]!=']' && i<line.length()){
				buf[idx++] = line[i++];
			}
			buf[idx]='\0';
			idx=0;
			if(insertAtEnd){
				beiju.push_back(buf);
			}
			else{
				beiju.push_front(buf);
			}
			if(i<line.length()){
				if(line[i]=='['){
					insertAtEnd=false;
				}
				else{
					insertAtEnd=true;
				}
			}
		}
		for(auto it=beiju.begin(); it!=beiju.end(); ++it){
			cout << *it;
		}
		cout<<"\n";
	}
	return 0;
}