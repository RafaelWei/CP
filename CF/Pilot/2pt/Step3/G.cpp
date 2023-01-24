#include<bits/stdc++.h>

using namespace std;

int n;
long long c;
string s;
int counta=0;
int countb=0;
int l=0;
long long rudeness=0;
int ans=INT_MIN;

void add(char c) 
{
    if (c == 'a')
    {
       counta++;
    }
    if (c == 'b')
    {
       rudeness += counta;
       countb++;
    }
} 

bool good()
{
    return rudeness <= c;
}

void remove(char c)
{
    if (c == 'a')
    {
        rudeness -= countb;
        counta--;
    }
    if (c == 'b')
    {
        countb--;
    }
}

int main()
{
    cin >> n >> c;
    cin >> s;

    for (int r=0; r<n; r++)
    {
        add(s[r]);
        while(!good())
        {
            remove(s[l]);
            l++;
        }
        ans = max(ans, r-l+1);
    }

    cout << ans << "\n";

    return 0;
}
