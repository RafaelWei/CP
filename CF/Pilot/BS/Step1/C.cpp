#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    vector<int> arr;
    arr.reserve(100000);

    cin >> n >> k;

    int tmp;

    for (int i=0; i<n; i++) 
    {
        cin >> tmp;
        arr.push_back(tmp);
    }

    for (int i=0; i<k; i++) 
    {
        cin >> tmp;
        int l=0, r=n-1;
        int idx = -1;
        while (l<=r) 
        {
            int mid = l + (r-l)/2;
            if (arr[mid] >= tmp)
            {
                idx = mid;
                r = mid-1;
            }
            else 
            {
                l = mid+1;
            }
        }

        if (idx != -1) 
        {
            cout << idx+1 << "\n";
        }
        else 
        {
            cout << n+1 << "\n";
        }
    }

    return 0;
}
