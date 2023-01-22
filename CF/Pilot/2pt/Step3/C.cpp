#include<bits/stdc++.h>

using namespace std;

long long n, r;
long long d[300001];

int main()
{
    cin >> n >> r;
    long long temp = 0;

    for (int i=1; i<=n; i++)
    {
        cin >> d[i];
        d[i] = d[i] - temp;
        temp = d[i] + temp;
    }
    
    
    int l=2;
    long long curr=0;
    long long ans=0;

    for (int i=2; i<=n; i++)
    {
        curr += d[i];

        while(curr - d[l] >r)
        {
            curr -= d[l];
            l++;
        }
        
        if (curr > r) ans += l-1;
    }

    cout << ans << "\n";

    return 0;
}
