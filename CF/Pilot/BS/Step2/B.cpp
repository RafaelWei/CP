#include<bits/stdc++.h>

using namespace std;

int n, k;
int arr[10005];

bool good(double x)
{
    int total = 0;
    for (int i=0; i<n; i++) 
    {
        total += floor(arr[i]/x);
    }

    return total >= k;
}

int main()
{
    cin >> n >> k;

    for (int i=0; i<n; i++) 
    {
        cin >> arr[i];
    }

    double l = 0; 
    double r = 1e8;
    double mid;

    for (int i=0; i<100; i++) 
    {
        mid = (l+r)/2;
        if (good(mid)) 
        {
            l = mid;
        }
        else 
        {
            r = mid;
        }
    }
    
    cout << l << "\n";

    return 0;
}
