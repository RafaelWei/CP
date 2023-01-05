#include<bits/stdc++.h>

using namespace std;

int lower(vector<int>& arr, int target)
{
    int l = 0;
    int r = arr.size()-1;
    int mid; 
    
    int idx = -1;
    while (l<=r) 
    {
        mid = l + (r-l)/2;
        if (arr[mid] <= target) 
        {
            idx = mid;
            l = mid+1;
        }
        else 
        {
            r = mid-1;
        }
    }
    
    return idx;
}

int upper(vector<int>& arr, int target)
{
    int l=0;
    int r=arr.size()-1;
    int mid;

    int idx = -1;
    while (l<=r) 
    {
        mid = l + (r-l)/2;
        if (arr[mid] >= target) 
        {
            idx = mid;
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    
    return idx;
}

int main() 
{
    int n, k, tmp, le, ri;
    vector<int> arr;
    arr.reserve(100000);

    cin >> n;

    for (int i=0; i<n; i++) 
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());

    cin >> k;

    for (int i=0; i<k; i++) 
    {
        cin >> le >> ri;
        int lo = upper(arr, le);
        int hi = lower(arr, ri);
        
        if (lo == -1 || hi == -1) cout << 0;
        else cout << hi - lo + 1;

        if (i == k-1) cout << "\n";
        else cout << " ";
    }

    return 0;
}
