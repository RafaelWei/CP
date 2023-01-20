#include<bits/stdc++.h>

using namespace std;

int n, m;
int arr[200005];
string t, p;

bool possible(int idx) 
{
    bool take[200005] = {};
    for (int i=0; i<idx; i++) take[arr[i]] = true;
    
    int p1=0, p2=0;
    
    while (p1<n && p2<m) 
    {
        if (take[p1])
        {
            p1++;
            continue;
        }

        if (t[p1] == p[p2]) 
        {
            p1++;
            p2++;
        }
        else
        {
            p1++;
        }

    }

    return p2 == m;
}

int main()
{
    cin >> t;
    cin >> p;

    n = t.size();
    m = p.size();

    for (int i=0; i<n; i++) {
        cin >> arr[i];
        arr[i]--;
    }

    int lo = 0;
    int hi = 200000;

    while (hi > lo+1) 
    {
        int mid = (hi+lo) >> 1;

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
