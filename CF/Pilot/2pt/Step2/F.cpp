#include<bits/stdc++.h>

using namespace std;

struct minmaxStack {
    vector<long long> s, smin{LLONG_MAX}, smax{LLONG_MIN};

    bool empty() {
        return s.size() == 0;
    }
    
    void push(long long x) 
    {
        s.push_back(x);
        smin.push_back(::min(x,smin.back())); 
        smax.push_back(::max(x,smax.back()));
    }

    long long pop()
    {
        long long temp = s.back();
        s.pop_back();
        smin.pop_back();
        smax.pop_back();
        return temp;
    }

    long long min()
    {
        return smin.back();
    }

    long long max()
    {
        return smax.back();
    }
};

int n;
long long k;
long long a[100005];
minmaxStack s1, s2;

void add(long long x) {
    s2.push(x); 
}

bool good() {
    long long lower = min(s1.min(), s2.min());
    long long higher = max(s1.max(), s2.max());

    return higher - lower <= k;
}

void remove() {
    if (s1.empty())
    {
        while (!s2.empty())
        {
            s1.push(s2.pop());
        }
    }
    s1.pop();
}

int main()
{
    cin >> n >> k;

    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    long long ans = 0;
    int l=0;
    for (int r=0; r<n; r++)
    {
        add(a[r]);
        while(!good())
        {
            remove();
            l++;
        }
        ans += r-l+1;
    }
    
    cout << ans << "\n";

    return 0;
}
