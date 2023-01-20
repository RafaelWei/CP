#include<bits/stdc++.h>

using namespace std;

int n;
long long s;
long long arr[100005];

int main()
{
    cin >> n >> s;

    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int l=0;
    long long curr=0;
    long long cnt=0;

    for (int r=0; r<n; r++)
    {
        curr += arr[r];

        while (curr >= s) 
        {
            curr -= arr[l];
            l++;
        }

        cnt += l;
    }

    cout << cnt << "\n";

    return 0;
}
