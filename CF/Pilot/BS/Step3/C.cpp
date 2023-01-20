#include<bits/stdc++.h>

using namespace std;

int n, k;
int stalls[10004];

bool possible(int dist)
{
    int cnt = 1;
    int pt1 = 0;
    int pt2 = 1;

    while (cnt < k && pt2 < n)
    {
        if (stalls[pt2] - stalls[pt1] >= dist)
        {
            cnt++;
            pt1 = pt2;
            pt2++;
        }
        else 
        {
            pt2++;
        }
    }

    return cnt == k;
}

int main()
{
    cin >> n >> k;

    for (int i=0; i<n; i++) 
    {
        cin >> stalls[i];
    }

    int lo = 1;
    int hi = 1e9;

    while (hi > lo+1) 
    {
        int mid = lo + (hi-lo)/2;
        if (possible(mid)) 
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }

    cout << lo << "\n";

    return 0;
}
