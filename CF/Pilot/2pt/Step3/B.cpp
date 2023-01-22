#include<bits/stdc++.h>

using namespace std;

int n;
long long s;
long long arr[100005];

int main()
{
    cin >> n >> s;

    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    long long l = 0;
    long long curr = 0;
    long long ans = 0;

    for (long long r=0; r<n; r++)
    {
        curr += arr[r];

        while (curr > s)
        {
            curr -= arr[l];
            l++;
        }
        ans += ((1 + r-l+1) * (r-l+1))/2;
    }

    cout << ans << "\n";


    return 0;
}
