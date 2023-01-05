#include<bits/stdc++.h>

using namespace std;

int p[100000];
int q[100000];

int main(){
    int T, N, pos=0, initialPos=0, sum=0, mn=INT_MAX;
    scanf("%d", &T);
    for(int j=0; j<T; j++){
        scanf("%d", &N);
        for(int i=0; i<N; i++){
            scanf("%d", &p[i]);
        }
        for(int i=0; i<N; i++){
            scanf("%d", &q[i]);
        }
        for(int i=0; i<N; i++){
            sum+=p[i]-q[i];
            mn=min(mn,sum);
        }
        int index=0;
        while(mn<0 && index<N){
            mn -= p[index]-q[index++];
        }
        if(index==N || sum<0){
            printf("Case %d: Not possible", j+1);
        }
        else{
            printf("Case %d: Possible from station %d", j+1, index+1);
        }
        sum=0;
        mn=INT_MAX;
    }

    return 0;
}
