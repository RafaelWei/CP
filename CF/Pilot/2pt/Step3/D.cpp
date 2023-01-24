#include<bits/stdc++.h>

using namespace std;

int n[4];
int garment[4][100005];
bool done[4] = {};

int min4(int a, int b, int c, int d)
{
    return min(min(a,b), min(c,d));
}

int max4(int a, int b, int c, int d)
{
    return max(max(a,b), max(c,d));
}

int main()
{
    for (int i=0; i<4; i++)
    {
       cin >> n[i];
        for (int j=0; j<n[i]; j++)
        {
           cin >> garment[i][j]; 
        }
        sort(garment[i], garment[i] + n[i]);
        garment[i][n[i]] = garment[i][n[i]-1];
    }

    int p0=0, p1=0, p2=0, p3=0;
    int curr = INT_MAX;
    int ans[4] = {};
    
    while(p0<n[0] || p1<n[1] || p2<n[2] || p3<n[3]) 
    {
        int left_bound = min4(garment[0][p0], garment[1][p1], garment[2][p2], garment[3][p3]);
        int right_bound = max4(garment[0][p0], garment[1][p1], garment[2][p2], garment[3][p3]);

        if (right_bound - left_bound < curr) {
            curr = right_bound - left_bound;
            ans[0] = garment[0][p0];
            ans[1] = garment[1][p1];
            ans[2] = garment[2][p2];
            ans[3] = garment[3][p3];
        }
        
        if (left_bound == garment[0][p0])
        {
            if (done[0]) break;
            else {
                p0++;
                if (p0 == n[0]) done[0] = true;
            }
        }
        else if (left_bound == garment[1][p1])
        {
            if (done[1]) break;
            else {
                p1++;
                if (p1 == n[1]) done[1] = true;
            }
        }
        else if (left_bound == garment[2][p2])
        {
            if (done[2]) break;
            else {
                p2++;
                if (p2 == n[2]) done[2] = true;
            }
        }
        else if (left_bound == garment[3][p3])
        {
            if (done[3]) break;
            else {
                p3++;
                if (p3 == n[3]) done[3] = true;
            }
        }
    }            

    for (int i=0; i<4; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
