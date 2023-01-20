#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll m, n, t[1005], z[1005], y[1005];

bool possible(ll time) 
{
    // sum the max ballons for each assistant
    ll total = 0;
    for (int i=0; i<n; i++)
    {
        ll batch_time = t[i]*z[i] + y[i];
        ll batches = time / batch_time;
        ll rem_time = time % batch_time;

        ll assist_total = batches * z[i];
        if (rem_time != 0)
        {
            if (rem_time >= t[i]*z[i])
            {
                assist_total += z[i];
            }
            else 
            {
                assist_total += rem_time/t[i];
            }
        }
        total += assist_total;
    }

    return total >= m;
}

void print_balloons(ll time) {
    ll total_balloons = 0;
    for (int i=0; i<n; i++) {
        ll batch_time = t[i]*z[i] + y[i];
        ll batches = time / batch_time;
        ll rem_time = time % batch_time;

        ll assist_total = batches * z[i];
        if (rem_time != 0)
        {
            if (rem_time >= t[i]*z[i])
            {
                assist_total += z[i];
            }
            else 
            {
                assist_total += rem_time/t[i];
            }
        }

        if (total_balloons + assist_total >= m)
        {
           cout << m - total_balloons;
           total_balloons = m;
        }
        else
        {
            cout << assist_total;
            total_balloons += assist_total;
        }

        cout << " ";
    }
    cout << endl;
}

int main() 
{
    cin >> m >> n;

    for (int i=0; i<n; i++)
    {
        cin >> t[i] >> y[i] >> z[i];
    }

    // binary search the valid times
    ll lo = -1;
    ll hi = 1e9;

    while (hi > lo+1) 
    {
        ll mid = (hi+lo) >> 1;

        if (possible(mid)) 
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }

    cout << hi << "\n";
    print_balloons(hi);

    return 0;
}
