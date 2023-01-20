#include<bits/stdc++.h>

using namespace std;

int n, k;
pair<double, double> arr[100005];

bool possible(double x) {
    double sum = 0;
    double temp[n];

    for (int i=0; i<n; i++)
    {
        temp[i] = arr[i].first - x*arr[i].second;
    }

    sort(temp, temp+n, greater<double>());

    for (int i=0; i<k; i++)
    {
        sum += temp[i];
    }

    return sum >= 0;
}

int main()
{
    cin >> n >> k;

    for (int i=0; i<n; i++) 
    {
        double ai, bi;
        cin >> ai >> bi;
        arr[i] = make_pair(ai, bi);
    }


    double lo = 0;
    double hi = 1e5;

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

    cout << setprecision(10);
    cout << lo << "\n";

    return 0;
}
