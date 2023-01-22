#include<bits/stdc++.h>

using namespace std;

int n;
long long s;
long long w[100001];
long long c[100001];
long long prefix[100001];

int main()
{
    cin >> n >> s;

    for (int i=1; i<=n; i++)
    {
        cin >> w[i];
    }

    for (int i=1; i<=n; i++)
    {
        cin >> c[i];
    }

    for (int i=1; i<=n; i++) 
    {
        prefix[i] = prefix[i-1] + c[i];
    }

    int l=1;
    long long ans=0;
    long long curr_weight=0;

    for (int r=1; r<=n; r++)
    {
        curr_weight += w[r];

        while (curr_weight > s)
        {
            curr_weight -= w[l];
            l++;
        }

        ans = max(ans, prefix[r] - prefix[l-1]);
    }

    cout << ans << "\n";
        
    return 0;
}
