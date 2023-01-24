#include<bits/stdc++.h>

using namespace std;

int n, m;
long long s, A, B;
long long items[200004];
int l=0;
long long ans=0;
long long currw=0;
long long currc=0;

void add(int idx)
{
    if (idx<n) currw += A;
    else currw += B;

    currc += items[idx];
}

bool good()
{
    return currw <= s;
}

void remove(int idx)
{
    if (idx<n) currw -= A;
    else currw -= B;

    currc -= items[idx];
}

int main()
{

    cin >> n >> m >> s >> A >> B;

    for (int i=n-1; i>=0; i--)
    {
        cin >> items[i];
    }
    sort(items, items+n);

    for (int i=n; i<n+m; i++)
    {
        cin >> items[i];
    }
    sort(items+n, items+n+m, greater<long long>());

    for (int r=0; r<n+m; r++)
    {
        add(r);
        while(!good())
        {
            remove(l);
            l++;
        }
        ans = max(ans, currc);
    }

    cout << ans << "\n"; 

    return 0;
}
