#include<bits/stdc++.h>

using namespace std;

long long fastExp(long long x, long long y)
{
    long long temp = 1;
    while (y>0)
    {
        if (y%2 == 1) temp *= x;
        x = x*x;
        y >>= 1;
    }
    
    return temp;
}

int main()
{

    long long x = 7;
    long long y = 10;
    cout << fastExp(x, y) << endl;

    return 0;
}
