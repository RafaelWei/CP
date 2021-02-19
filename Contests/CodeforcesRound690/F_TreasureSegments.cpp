#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void solve(){
	int n;
	scanf("%d", &n);
	vi L;
	vi R;
	vector< pair<int,int> > vec(n);

	for(auto &[l,r]:vec){
		scanf("%d %d", &l, &r);
		L.push_back(l);
		R.push_back(r);
	}

	sort(L.begin(), L.end());
	sort(R.begin(), R.end());

	int ans = n-1;
	for(auto [l, r]: vec){
		int left = lower_bound(R.begin(), R.end(), l) - R.begin();
		int right = max(0, n-(int)(upper_bound(L.begin(), L.end(), r)-L.begin()));
		ans = min(ans, right+left);
	}

	printf("%d\n", ans);
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		solve();
	}
}