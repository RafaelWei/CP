#include<bits/stdc++.h>

using namespace std;

int main(){
    int T, w, qtd=0, maxW=0;
    string str;
    string ans[10];

    cin >> T;

    for(int j=0; j<T; j++){
        for(int i=0; i<10; i++){
            cin>> str >> w;
            if(w>maxW){
                ans[0]=str;
                maxW=w;
                qtd=1;
            }
            else if(w==maxW){
                ans[qtd++]=str;
            }
        }

        cout << "Case #" << j+1 << ":\n";
        for(int i=0; i<qtd; i++){
            cout << ans[i] << "\n";
        }
        maxW=0;
        qtd=0;
    }

    return 0;
}
