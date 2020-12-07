#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k, m;
    char ch;
    map<char, double> mp;
    map<char, double>::iterator it;
    string str;
    double aux, total=0;

    cout << setprecision(2) << fixed;
    cin >> n;
    while(n--){
        cin >> k;
        for(int i=0; i<k; i++){
            cin >> ch >> aux;
            mp[ch]=aux;
        }
        cin >> m;
        cin.ignore();
        for(int i=0;i<m; i++){
            str="";
            getline(cin, str);
            for(int j=0; j<str.size(); j++){
                it = mp.find(str[j]);
				if(it != mp.end())
					total += it->second;
            }
        }

        total/=100;
        cout << total << "$\n";
        mp.clear();
        total=0;
    }
    return 0;
}
