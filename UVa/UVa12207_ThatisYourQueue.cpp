#include<bits/stdc++.h>

using namespace std;

int main(){
    int p, c, aux, n_case=1;
    char ch;
    deque<int> d;
    deque<int>::iterator it;

    while(scanf("%d %d", &p, &c) && p!=0 && c!=0){
        d.clear();
        printf("Case %d:\n", n_case++);
        for(int i=0;i<p;i++){
            d.push_back(i+1);
        }
        for(int i=0; i<c; i++){
            scanf("%c", &ch);
            if(ch=='N'){
                aux = d.front();
                printf("%d\n", d[0]);
                d.push_back(aux);
            }
            else{
                scanf("%d", &aux);
                it = find(d.begin(), d.end(), aux);
                d.erase(it);
                d.push_front(aux);
            }
        }
    }

    return 0;
}
