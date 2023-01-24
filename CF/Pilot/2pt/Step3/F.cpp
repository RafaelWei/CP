#include<bits/stdc++.h>

using namespace std;

string s, letters;
int n, m;
int cnt[30];
bool good = true;

void add(int x)
{
    cnt[x]--;
    if (cnt[x] < 0) good = false;
}

void remove(int x)
{
    cnt[x]++;
    if(cnt[x] == 0) good = true; 
}

int main()
{
    cin >> n >> m;

    cin >> s;
    cin >> letters;

    for (int i=0; i<m; i++)
    {
        cnt[letters[i] -'a']++;
    }

    int l =0;
    long long ans = 0;
    for (int r=0; r<n; r++)
    {
        add(s[r]-'a');
        while(!good)
        {
            remove(s[l]-'a');
            l++;
        }
        ans += r-l+1;
    }

    cout << ans << "\n";  

    return 0;
}
