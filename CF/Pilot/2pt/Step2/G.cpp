#include<bits/stdc++.h>

using namespace std;

long long gcd(long long x, long long y)
{
    return y == 0 ? x : gcd(y, x%y);
}

struct gcdStack
{
    vector<long long> s, gcds;

    bool empty()
    {
        return s.size()==0;
    }

    void push(long long x)
    {
        s.push_back(x);
        if (gcds.size() == 0)
        {
           gcds.push_back(x);
        }
        else
        {
           gcds.push_back(::gcd(x,gcds.back()));
        } 
    }

    long long pop() 
    {
        long long temp = s.back();
        s.pop_back();
        gcds.pop_back();
        return temp;
    }

    long long gcd()
    {
        return gcds.back();
    }

    bool only1() 
    {
        return (gcds.size() == 1 && gcds.back() == 1);
    }
};

int n;
gcdStack s1, s2;
long long a[100005];

void add(long long x) 
{
    s2.push(x);
}

bool good()
{
    if (s1.empty() && s2.empty()) return false;
    else if (s1.empty()) return (s2.gcd()==1);
    else if (s2.empty()) return (s1.gcd()==1);
    else return gcd(s1.gcd(),s2.gcd()) == 1;
}

void remove()
{
    if (s1.empty())
    {
        while(!s2.empty())
        {
            s1.push(s2.pop());
        }
    }
    s1.pop();
}

int main()
{
    cin >> n;

    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    int l=0;
    int ans = INT_MAX;

    for (int r=0; r<n; r++)
    {
        add(a[r]);
        while(good())
        {
            ans = min(ans, r-l+1);
            remove();
            l++;
        }
    } 
    
    if (ans == INT_MAX) ans = -1;
    cout << ans << "\n";
        
    return 0;
}
