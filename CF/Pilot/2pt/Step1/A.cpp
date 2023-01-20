#include<bits/stdc++.h>

using namespace std;

int a[100005], b[100005];
int c[200005];

int main()
{
    int n, m;

    cin >> n >> m;

    for (int i=0; i<n; i++) 
    {
        cin >> a[i];
    }

    for (int i=0; i<m; i++) 
    {
        cin >> b[i];
    }

    int pa=0, pb=0;
    int pc = 0;

    while (pa<n && pb<m) 
    {
        if (a[pa] <= b[pb])
        {
            c[pc] = a[pa];
            pa++;
            pc++;
        }
        else 
        {
            c[pc] = b[pb];
            pb++;
            pc++;
        }
    }

    if (pa == n) 
    {
        while (pb < m)
        {
            c[pc] = b[pb];
            pb++;
            pc++;
        }
    }

    else
    {
        while (pa < n)
        {
            c[pc] = a[pa];
            pa++;
            pc++;
        }
    }


    for (int i=0; i<n+m; i++)
    {
        cout << c[i];
        if (i<n+m-1) cout << " ";
        else cout << "\n";
    }

    return 0;
}

