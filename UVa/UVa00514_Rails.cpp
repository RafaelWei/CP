#include<bits/stdc++.h>

using namespace std;
int n;
stack<int> s;

void solve(){
    while(1){
        int j=0, m;
        while(!s.empty()){
            s.pop();
        }
        for(int i=0; i<n; i++){
            scanf("%d", &m);
            if(m==0) return;
            while(j!=m && j<n){
                if(!s.empty() && s.top()==m) break;
                j++;
                s.push(j);
            }
            if(!s.empty() && s.top()==m){
                s.pop();
            }
        }
        if(s.empty()) printf("Yes\n");
        else printf("No\n");
    }

}

int main(){
    while(scanf("%d", &n) && n!=0){
        solve();
        printf("\n");
    }

    return 0;
}
