#include<bits/stdc++.h>

using namespace std;

int main(){
    int blank[13];
    string str;
    int n;
    int cnt;
    int res;
    int minBlank;

    scanf("%d", &n);
    while(n!=0){
        res=0;
        cnt=0;
        minBlank=50;
        for(int i=0; i<n; i++){
            cin.ignore();
            getline(cin, str);

            for(int j=0; j<str.length(); j++){
                if(str[j]==' '){
                    cnt++;
                }
            }
            blank[i]=cnt;
            minBlank = min(minBlank, cnt);
            cnt=0;
        }

        for(int i=0; i<n; i++){
            res+=blank[i]-minBlank;
        }

        printf("%d\n", res);
        scanf("%d", &n);
    }
    return 0;
}
