#include<bits/stdc++.h>

using namespace std;

long long n;
long long p;
long long arr[2005];

int main() 
{
    cin >> n >> p;
    long long list_positivity = 0;

    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
        arr[i+n] = arr[i];
        list_positivity += arr[i];
    }

    long long replay = p/list_positivity;
    long long target_sum = p%list_positivity;
    bool jump = false;

    long long idx_start=0;
    long long smallest=1e9;
    if (target_sum == 0)
    {
        jump = true;
        smallest = 0;
    }

    long long l=0;
    long long curr=0;
    
    if (!jump){
        for (long long r=0; r<2*n-1; r++)
        {
            curr += arr[r];
            
            while (curr - arr[l] >= target_sum)
            {
                curr -= arr[l];
                l++;
            }

            if (curr >= target_sum)
            {
                if (r-l+1 < smallest) 
                {
                    smallest = r-l+1;
                    idx_start = l;
                }
            }
        }
    }
    
    cout << idx_start + 1 <<  " " << smallest+replay*n << "\n";

    return 0;
}
