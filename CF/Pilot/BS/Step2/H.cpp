#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

string hamb;
ll nb, ns, nc;
ll pb, ps, pc;
ll rubles;
ll hb, hs, hc;

bool possible(ll nhamb)
{
    ll rem_rubles = rubles;
    // check if we can have enough bread
    ll req_bread = nhamb * hb;
    ll buy_bread = max(0LL, req_bread - nb);
    rem_rubles -= buy_bread * pb;
    if (rem_rubles < 0) return false;

    ll req_sausage = nhamb * hs;
    ll buy_sausage = max(0LL, req_sausage - ns);
    rem_rubles -= buy_sausage * ps;
    if (rem_rubles < 0) return false;

    ll req_cheese = nhamb * hc;
    ll buy_cheese = max(0LL, req_cheese - nc);
    rem_rubles -= buy_cheese * pc;
    if (rem_rubles < 0) return false;
    
    return true;
}

int main() 
{
    cin >> hamb;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> rubles;


    for (auto ch : hamb) 
    {
        switch(ch)
        {
            case 'B':
                hb++;
                break;
            case 'S':
                hs++;
                break;
            case 'C':
                hc++;
                break;
            default:
                break;
        }
    }

    ll lo = 0;
    ll hi = 1e13 + 1000;

    while (hi > lo+1) 
    {
        ll mid = (hi+lo) >> 1;
        if (possible(mid))
        {
            lo = mid;
        }
        else 
        {
            hi = mid;
        }
    }

    cout << lo << "\n";

    return 0;
}
