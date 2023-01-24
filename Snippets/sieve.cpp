#include<bits/stdc++.h>

using namespace std;

bool prime[1000000];

void fillSieve(int n)
{
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;

    for (int p=2; p<n; p++)
    {
        if (prime[p] == true)
        {
            for(int i=p*p; i<=n; i+=p)
            {
                prime[i] = false;
            }
        }
    }
}

int main()
{
    fillSieve(1000);
    for (int i=0; i<1000; i++)
    {
        if (prime[i]) cout << i << endl;
    }

    return 0;
}
