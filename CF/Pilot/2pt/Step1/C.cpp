#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a[100005];
    int b[100005];

    int n,m;

    cin >> n >> m;

    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    for (int i=0; i<m; i++)
    {
        cin >> b[i];
    }

    int i=0, j=0;
    int ans = 0;
    while (i<n && j<m)
    {
        if (a[i] > b[j]) j++;
        else if (a[i] < b[j]) i++;
        else
        {
            int temp = a[i];
            int ina=0, inb=0;
            while (i<n && a[i] == temp)
            {
                ina++;
                i++;
            }
            while (j<m && b[j] == temp) 
            {
                inb++; 
                j++;
            }
            ans += ina*inb;
        }
    } 

    cout << ans << "\n";

    return 0;
}
