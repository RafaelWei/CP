#include<bits/stdc++.h>

using namespace std;

long long k, n;
long long arr[55];

bool possible (long long councils) 
{
    long long sum = 0;
    for (int i=0; i<n; i++)
    {
        sum += min(councils, arr[i]);
    }

    return sum >= k*councils;
}

int main()
{
    cin >> k;
    cin >> n;
    
    long long limit = 0;
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
        limit += arr[i];
    }

    long long hi = limit/k + 100;
    long long lo = 1;

    while (hi > lo+1) 
    {
        long long mid = (hi + lo) >> 1;
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
