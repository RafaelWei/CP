#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, k;
ll arr[100005];

bool possible(ll targetSum)
{
    int segs=1;

    int i=0;
    ll currSum=0;

    while (i<n) 
    {
        if (arr[i] > targetSum) return false;

        if (segs > k) break;

        if (currSum + arr[i] > targetSum)
        {
            segs++;
            currSum = 0;
            continue;
        }
        else
        {
            currSum += arr[i];
            i++;
        }
    }

    return segs <= k; 
}

int main() 
{
    cin >> n >> k;

    for (int i=0; i<n; i++) 
    {
        cin >> arr[i];
    }

    ll lo = 0;
    ll hi = 1e14;

    while (hi > lo+1)
    {
        ll mid = (hi+lo) >> 1;

        if (possible(mid))
        {
            hi = mid;
        }
        else 
        {
            lo = mid;
        }
    }    

    cout << hi << "\n";

    return 0;
}
