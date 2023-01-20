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

    int l=0, r=0;
    long long curr=0;
    int longest=0;

    while(r<n)
    {
        while(r<n && curr<=s)
        {
            curr += arr[r];
            r++;
        }    

        longest = max(longest, r-l-1);
        
        while(curr > s)
        {
            curr -= arr[l];
            l++;
        }

    }
  
    longest = max(longest, r-l);

    cout << longest << "\n";

    return 0;
}
