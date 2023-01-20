#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long s;
    long long arr[100005];

    cin >> n >> s;

    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int l=0, r=0;
    int smallest = 1e9 + 10;
    long long curr = 0;
    long long temp;

    while (r<n)
    {
        while (r<n && curr < s)
        {
            curr += arr[r];
            r++;
        }
        temp = curr;

        while (curr >= s)
        {
            curr -= arr[l];
            l++;
        }

        if (temp >= s) smallest = min(smallest, r-l+1);

    }

    smallest = smallest == 1e9 + 10 ? -1 : smallest;
    cout << smallest << "\n";

    return 0;
}
