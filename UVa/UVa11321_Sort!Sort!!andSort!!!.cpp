#include<bits/stdc++.h>
using namespace std;

int n, m;

bool cmp(const int &i, const int &j){
	if (i % m != j % m)
        return i % m < j % m;
    if (i & 1) // i is odd
    {
        if (j & 1)
            return i > j;
        return true;
    }
    if (j & 1)
    {
        return false;
    }
    return i < j;
}

void solve(){
	vector<int> v(n);
	for(int i=0; i<n; i++){
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.begin()+n, cmp);
	printf("%d %d\n", n, m);
	for(int i=0; i<n; i++){
		printf("%d\n", v[i]);
	}
}

int main(){
	while(scanf("%d %d", &n, &m) && n!=0 && m!=0){
		solve();
	};
	printf("%d %d\n", n, m);
	return 0;
}