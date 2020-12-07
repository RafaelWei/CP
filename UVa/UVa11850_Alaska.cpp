#include<bits/stdc++.h>

using namespace std;

int stations[1500];

int main(){
    int n;
    bool notPossible = false;

    while(scanf("%d", &n) && n!= 0){
        for(int i=0; i<n; i++){
            scanf("%d", &stations[i]);
        }
        sort(stations, stations+n);
        for(int i=1; i<n; i++){
            if(stations[i]-stations[i-1]>200){
                printf("IMPOSSIBLE\n");
                notPossible = true;
                break;
            }
        }
        if(notPossible){
            notPossible = false;
            continue;
        }
        if(2*(1422 - stations[n-1]) > 200){
            printf("IMPOSSIBLE\n");
            continue;
        }
        printf("POSSIBLE\n");
    }

    return 0;
}
