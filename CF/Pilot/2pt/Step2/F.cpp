#include<bits/stdc++.h>

using namespace std;

int n;
long long k;
long long arr[100005];
stack<long long> s1;
stack<long long> s1Max;
stack<long long> s1Min;
stack<long long> s2;

int main()
{
    cin >> n >> k;

    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    long long ans = 0;
    long long hi =0;
    long long lo = LONG_MAX;

    for (int r=0; r<n; r++)
    {
        s2.push(arr[r]);
        hi = max(hi, arr[r]);
        lo = min(lo, arr[r]);

        if (s1.empty()) {
            while(!s2.empty()) {
                long long temp = s2.top();
                s2.pop();
                s1.push(temp);
                if (s1Max.empty() || s1Max.top() < temp) s1Max.push(temp);
                if (s1Min.empty() || s1Min.top() < temp) s1Min.push(temp);
            }
            hi=0;
            lo=LONG_MAX;
        }       

        long long curr_max = max(hi, s1Max.top());
        long long curr_min = min(lo, s1Min.top());

        while (curr_max - curr_min > k)
        {
            s1.pop();
            s1Max.pop();
            s1Min.pop();
            curr_max = max(hi, s1Max.top());
            curr_min = min(lo, s1Min.top());
        }
            
        ans += s1.size() + s2.size();
    }
    
    cout << ans << "\n";

    return 0;
}
