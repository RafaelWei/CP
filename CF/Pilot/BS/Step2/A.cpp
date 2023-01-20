#include<bits/stdc++.h>

using namespace std;

bool isGood(long long w, long long h, long long x, long long n)
{ 
    return (x/w) * (x/h) >= n; 
}

int main() 
{
    long long w, h, n;

    cin >> w >> h >> n;
    
    long long l=0, r=1;
    while (!isGood(w, h, r, n)) r*=2;

    long long mid;
    long long ans = -1;
    while (l<=r) 
    {
        mid = l + (r-l)/2;
        if (isGood(w, h, mid, n)) 
        {
            ans = mid;
            r = mid-1;
        }
        else 
        {
            l = mid+1;
        }
    }

    cout << ans << "\n";

    return 0;
}
