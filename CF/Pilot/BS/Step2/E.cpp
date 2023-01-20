#include<bits/stdc++.h>

using namespace std;

int main()
{
    double c;
    cin >> c;

    double l = 0.0;
    double r = 1e6;

    for (int i=0; i<100; i++) 
    {
        double mid = (l+r)/2;
        if ( mid*mid + sqrt(mid) > c) {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }

    cout << setprecision(20);
    cout << l << "\n"; 

    return 0;
}
