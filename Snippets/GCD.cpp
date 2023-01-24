#include<bits/stdc++.h>

using namespace std;

int gcd(long long x, long long y)
{
    return y == 0 ? x : gcd(y, x%y);
}

int main()
{
    long long x=749;
    long long y=105;

    cout << gcd(x, y) << endl;

    return 0;
}
