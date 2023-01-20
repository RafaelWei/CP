#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int a[100005];
    int b[100005];

    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    for (int i=0; i<m; i++)
    {
        cin >> b[i];
    }

    int pta=0;
    int ans[100005];

    for (int i=0; i<m; i++)
    {
        while(pta<n && a[pta]<b[i])
        {
            pta++;
        }
        ans[i] = pta;
    }

    for (int i=0; i<m; i++) 
    {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
