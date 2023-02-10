#include<bits/stdc++.h>

using namespace std;

int T, n;
bool adj[100][100];
bool visited[100];
bool visited2[100];

void printAns(char ans[100][100])
{
    for (int i=0; i<n; i++)
    {
        cout << '+';
        for (int j=0; j<2*n-1; j++) cout << '-';
        cout << '+' << "\n";

        for (int j=0; j<n; j++)
        {
            cout << '|' << ans[i][j];
        }
        cout << '|' << "\n";
    }

    cout << '+';
    for (int j=0; j<2*n-1; j++) cout << '-';
    cout << '+' << "\n";
}

void dfs(int x)
{
    visited[x] = true;
    for (int i=0; i<n; i++)
    {
        if (adj[x][i] && !visited[i])
        {
            dfs(i);
        }
    }
}

void dfs2(int x, int removed)
{
    if (x == removed) return;
    visited2[x] = true;
    for (int i=0; i<n; i++)
    {
        if (adj[x][i] && !visited2[i])
        {
            dfs2(i,removed);
        }
    }
}

int main()
{
    int case_n = 0;
    cin >> T;

    while(T--)
    {
       char ans[100][100];
       memset(visited, false, sizeof(visited));
       cin >> n;
       for (int i=0; i<n; i++)
       {
          for (int j=0; j<n; j++)
          {
             cin >> adj[i][j];
          }
       }
       
       dfs(0);
       
       for (int i=0; i<n; i++)
       {
           memset(visited2, false, sizeof(visited2));
           dfs2(0, i);
           for (int j=0; j<n; j++)
           {
               if (visited[j] && !visited2[j]) ans[i][j] = 'Y';
               else ans[i][j] = 'N';
           }
       }
       
       cout << "Case " << ++case_n << ":\n"; 
       printAns(ans);
    } 


    return 0;
}
