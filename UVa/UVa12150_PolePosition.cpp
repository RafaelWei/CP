#include<bits/stdc++.h>

using namespace std;

int grid[1000];

int main(){
    int n, c, p;
    int carNumber, deltaPos;
    bool possible=true;

    while(scanf("%d", &n) && n!=0){
        memset(grid, -1, sizeof(grid));
        for(int i=0; i<n; i++){
            scanf("%d %d", &carNumber, &deltaPos);
            if(i+deltaPos<0 || i+deltaPos>=n || grid[i+deltaPos]!=-1){
                //printf("-1\n");
                possible = false;
                //break;
            }
            else{
                grid[i+deltaPos]=carNumber;
            }
        }
        if(possible){
            for(int i=0; i<n-1; i++){
                printf("%d ", grid[i]);
            }
            printf("%d\n", grid[n-1]);
        }
        else{
            printf("-1\n");
        }
        possible=true;
    }

    return 0;
}
