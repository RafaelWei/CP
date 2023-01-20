#include<bits/stdc++.h>

using namespace std;

int n,k;
int arr[100005], cnt[100005] = {};

int main()
{
    cin >> n >> k;

    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int l=0;
    long long ans = 0;
    int uniques = 0;
    for (int r=0; r<n; r++)
    {
        cnt[arr[r]]++;
        if (cnt[arr[r]] == 1) uniques++;

        while(uniques > k) {
            cnt[arr[l]]--;
            if (cnt[arr[l]] == 0) uniques--;
            l++;
        }
        ans += r-l+1;

    }

    cout << ans << "\n";

    return 0;
}
