#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
double x[100005];
double v[100005];

bool possible(double Time) 
{
    double lbound = -1e10;
    double rbound = 1e10;
    for (int i=0; i<n; i++)
    {
        lbound = max(lbound, x[i] - Time*v[i]);
        rbound = min(rbound, x[i] + Time*v[i]);
        if (lbound > rbound) return false;
    }
    
    return true;
}

int main() 
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> x[i] >> v[i];
    }

    double lo = -1;
    double hi = 2 * 1e9;

    for (int i=0; i<100; i++)
    {
        double mid = (hi+lo)/2;
        if (possible(mid))
        {
            hi = mid;
        }
        else 
        {
            lo = mid;
        }
    }

    cout << setprecision(20);
    cout << hi << "\n";

    return 0;
}
