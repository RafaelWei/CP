#include<bits/stdc++.h>

using namespace std;

int main(){
    int N, B, H, W, res=INT_MAX;
    int p;
    int weeks;

    while(scanf("%d %d %d %d", &N, &B, &H, &W)!=EOF){
        while(H--){
            scanf("%d", &p);
            for(int i=0; i<W; i++){
                scanf("%d", &weeks);
                if(weeks>=N){
                    res = min(res, N*p);
                }
            }
        }
        if(res>B) printf("stay home\n");
        else printf("%d\n", res);
        res=INT_MAX;
    }


    return 0;
}
