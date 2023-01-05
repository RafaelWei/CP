#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    vector<int> vec;
    vec.reserve(100000);

    cin >> n >> k;
    
    int tmp;
    for (int i=0; i<n; i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }
    
    int mid;
    for (int i=0; i<k; i++) {
        bool found = false;
        int l=0, r=n-1;
        cin >> tmp;
        while (l<=r)
        {
            mid = l + (r-l)/2;
            if (vec[mid] == tmp) 
            {
                found = true;
                break;
            }
            else if (vec[mid] < tmp) 
            {
                l = mid+1;
            }
            else
            {
               r = mid-1;
            }
        } 

        if (found) 
        {
            cout << "YES\n";
        }
        else 
        {
            cout << "NO\n";
        }
    }

    return 0;
}
