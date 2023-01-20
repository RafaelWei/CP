#include<bits/stdc++.h>

using namespace std;

long long n, x, y;

bool good(long long mid)
{
    if (mid < min(x,y)) return false;
    mid -= min(x,y);
    return ((mid/x + mid/y + 1) >= n);
}

int main()
{
    cin >> n >> x >> y;

    long long l = 0;
    long long r = n * min(x,y);

    while (l+1<r) 
    {
        long long mid = (l+r) >> 1;
        if (good(mid))
        {
            r=mid;
        }
        else
        {
            l=mid;
        }
    }

    cout << r << "\n";

    return 0;
}
