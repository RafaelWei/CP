#include<bits/stdc++.h>

using namespace std;

struct bitsetStack{
    vector<int> s;
    vector< bitset<1001> > b{1};

    bool empty()
    {
        return s.size() == 0;
    }

    void push(int x) 
    {
        s.push_back(x);
        bitset<1001> temp = b.back();
        b.push_back(temp | temp<<x);
    }

    int pop()
    {
        int temp = s.back();
        s.pop_back();
        b.pop_back();
        return temp;
    }

    bitset<1001> currSet()
    {
        return b.back();
    }
};

int n, s;
int a[100005];
bitsetStack st1, st2;

void add(int x)
{
    st2.push(x);
}

bool good()
{
    bitset<1001> b1 = st1.currSet();
    bitset<1001> b2 = st2.currSet();

    for (int i=0; i<=s; i++)
    {
        if (b1[i] & b2[s-i]) return true;
    }

    return false;
}

void remove()
{
    if (st1.empty())
    {
        while(!st2.empty())
        {
            st1.push(st2.pop());
        }
    }
    st1.pop();
}

int main()
{
    cin >> n >> s;

    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    int ans = INT_MAX;
    int l=0;
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

    if (ans == INT_MAX) ans=-1;
    cout << ans << "\n";

    return 0;
}
