#include<bits/stdc++.h>

using namespace std;

struct minmaxStack{
    vector<long long> s, smin={LLONG_MAX}, smax={LLONG_MIN};

    bool empty()
    {
        return s.size() == 0;
    }

    void push(long long x)
    {
        s.push_back(x);
        smin.push_back(::min(smin.back(), x));
        smax.push_back(::max(smax.back(), x));
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


int main()
{
    minmaxStack s;
    long long a[10] = {7, 3, 6, 3, 2, 8, 6, 10, 20, 12};

    for (int i=0; i<10; i++)
    {
        s.push(a[i]);
        cout << "max: " << s.max() << endl;
    }

    for (int i=0; i<10; i++)
    {
        s.pop();
        cout << "min: " << s.min() << endl;
    } 
    
    return 0;
}
