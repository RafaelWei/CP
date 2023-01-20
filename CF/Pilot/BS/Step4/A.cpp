#include<bits/stdc++.h>

using namespace std;

int n, d;
double arr[100005] = {};
double p[100005] = {};
double m[100005] = {};
int leftIdx[100005] = {};

int l, r;

bool possible(double avg)
{
    // build prefix sum and min arrys;
    for (int i=1; i<=n; i++)
    {
        p[i] = p[i-1] + arr[i] - avg;
    }

    m[0] = 0;
    for (int i=1; i<=n; i++)
    {
        m[i] = min(m[i-1], p[i]);
    }

    for (int i=d; i<=n; i++)
    {
        if (m[i-d] <= p[i]) 
        {
            r = i;
            for (int j=0; j<=i-d; j++) {
                if (p[i] >= p[j]) l = j+1;
            }
            return true;
        }
    }
    
    return false;
}

int main()
{
    cin >> n >> d;

    for (int i=1; i<=n; i++) 
    {
       cin >> arr[i];
    }
        
    double lo = -1;
    double hi = 105;

    for (int i=0; i<100; i++)
    {
        double mid = (hi+lo)/2;
        if (possible(mid))
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }

    cout << l << " " << r << "\n";
    return 0;
}
