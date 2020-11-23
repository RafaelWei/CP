#include<bits/stdc++.h>

using namespace std;

int main(){
	string str;
	bool flag=false;
	while(getline(cin, str)){
		string res;
		for(int i=0; i<str.length(); i++){
			if(str[i]=='"'){
				if(!flag){
					res+="``";
					flag=!flag;
				}
				else{
					res+="''";
					flag=!flag;
				}
			}
			else{
				res+=str[i];
			}
		}
		cout << res << "\n";
	}
	return 0;
}