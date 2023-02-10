#include<bits/stdc++.h>

#define WATER true
#define LAND false

using namespace std;

int T, R, C, M, N, W;
int xi, yi;
int evens, odds;
bool field[101][101];
bool visited[101][101];

const int numDirs = 4;

int dx[numDirs] = {1, 1, -1, -1};
int dy[numDirs] = {1,-1,  1, -1};

int zerodx[numDirs] = {1, -1, 0, 0};
int zerody[numDirs] = {0, 0, 1, -1};

bool isValid(int r, int c)
{
    if (r>=0 && r<R && c>=0 && c<C && field[r][c]==LAND) return true;
    return false;
}

void dfs(int x, int y);

int tryShifts(int x, int y, int rMultiple, int cMultiple)
{
    int cnt = 0;
    
    for (int i=0; i<numDirs; i++)
    {
        int nextx = x+dx[i]*rMultiple;
        int nexty = y+dy[i]*cMultiple;
        if (isValid(nextx,nexty))
        {
            cnt++;
            if (!visited[nextx][nexty])
            {
                dfs(nextx, nexty);
            }
        }
    }
    return cnt;
}

void dfs(int x, int y)
{
    visited[x][y] = true;
    int cnt = 0;

    if (M==0 || N==0)
    {
        int nonZero = max(M,N);
        for (int i=0; i<numDirs; i++)
        {
            int nextx = x+zerodx[i]*nonZero;
            int nexty = y+zerody[i]*nonZero;
            if (isValid(nextx, nexty))
            {
                cnt++; 
                if (!visited[nextx][nexty])
                {
                    dfs(nextx, nexty);
                }
            }
        }
    }
    else if (M==N)
    {
        cnt = tryShifts(x, y, M, M);    
    }
    else
    {
        cnt = tryShifts(x,y,M,N) + tryShifts(x,y,N,M);
    }

    if (cnt%2==0) evens++;
    else odds++;
}

int main()
{
    cin >> T;
    int case_n = 0;

    while(T--)
    {
        memset(field, false, sizeof(field));
        memset(visited, false, sizeof(visited));
        cin >> R >> C >> M >> N;

        cin >> W;
        for (int i=0; i<W; i++)
        {
            cin >> xi >> yi; 
            field[xi][yi] = WATER;
        }

        evens = 0;
        odds = 0;

        dfs(0,0);

        cout << "Case " << ++case_n << ": " << evens << " " << odds << "\n";

    }
    return 0;
}
