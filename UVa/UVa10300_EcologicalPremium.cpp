#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, f, space, n_animals, p, cnt=0;

    scanf("%d", &n);

    while(n--){
        scanf("%d", &f);
        while(f--){
            scanf("%d %d %d", &space, &n_animals, &p);
            cnt+=space*p;
        }
        printf("%d\n", cnt);
        cnt=0;
    }

    return 0;
}
