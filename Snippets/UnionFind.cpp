#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class UnionFind{
private:
    vi r, p;

public:
    UnionFind(int n){
       p.assign(n, 0);
       r.assign(n, 0);
       for(int i=0; i<n; i++){
            p[i]=i;
       }
    }

    int findSet(int i){
        return (p[i]==i) ? i : (p[i]=findSet(p[i]));
    }
    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j){
        if(!isSameSet(i, j)){
            int x = findSet(i);
            int y = findSet(j);
            if(r[x]>r[y]) p[y]=x;
            else{
                p[x] = y;
                if(r[x]==r[y]) r[y]++;
            }
        }
    }
};

int main(){
    UnionFind uf(5);
    uf.unionSet(0, 1);
    uf.unionSet(1, 4);
    uf.unionSet(2, 3);

    printf("%d\n", uf.isSameSet(1, 2));
    printf("%d\n", uf.isSameSet(1, 0));
    printf("%d\n", uf.isSameSet(0, 4));
    printf("%d", uf.isSameSet(3, 2));

    return 0;
}
