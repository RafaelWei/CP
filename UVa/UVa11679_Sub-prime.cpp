#include<bits/stdc++.h>

using namespace std;

int main(){
    int B, N;
    int banks[20];
    int deb, cre, V;
    int aux=1;

    while(scanf("%d %d", &B, &N) && B!=0 && N!=0){
        for(int i=0; i<B; i++){
            scanf("%d", &banks[i]);
        }
        for(int i=0; i<N; i++){
            scanf("%d %d %d", &deb, &cre, &V);
            banks[deb-1]-=V;
            banks[cre-1]+=V;
        }
        for(int i=0; i<B; i++){
            if(banks[i]<0){
                printf("N\n");
                aux=0;
                break;
            }
        }
        if(aux) printf("S\n");
        aux=1;
    }

    return 0;
}
