#include<bits/stdc++.h>

using namespace std;

int N, M, S;

int main()
{
    while (cin >> N >> M >> S && N!=0 && M!=0 && S!=0)
    {
        int n_stickers = 0;
        vector<string> arena;
        string temp;
        string instructions;
        int curr_row;
        int curr_col;
        char curr_dir;
        for (int i=0; i<N; i++)
        {
            cin >> temp;
            for (int j=0; j<M; j++)
            {
                if (temp[j] == 'N' || temp[j] == 'S' || temp[j] == 'L' ||temp[j] == 'O')
                {
                    curr_row = i;
                    curr_col = j;
                    curr_dir = temp[j];
                }
            }
            arena.push_back(temp);
        }    

        cin >> instructions;
        
        for (int i=0; i<S; i++)
        {
            if (instructions[i] == 'D')
            {
                switch (curr_dir)
                {
                    case 'N':
                       curr_dir = 'L';
                       break;
                    case 'L':
                       curr_dir = 'S';
                       break;
                    case 'S':
                       curr_dir = 'O';
                       break;
                    case 'O':
                       curr_dir = 'N';
                       break;
                    default:
                       break;
                }
                      
            }
            else if (instructions[i] == 'E')
            {
                switch (curr_dir)
                {
                    case 'N':
                       curr_dir = 'O';
                       break;
                    case 'L':
                       curr_dir = 'N';
                       break;
                    case 'S':
                       curr_dir = 'L';
                       break;
                    case 'O':
                       curr_dir = 'S';
                       break;
                    default:
                       break;
                }
            }
            else 
            {
                switch (curr_dir)
                {
                    case 'N':
                       if (curr_row != 0 && arena[curr_row-1][curr_col] != '#') curr_row -= 1;
                       break;
                    case 'L':
                       if (curr_col != M-1 && arena[curr_row][curr_col+1] != '#') curr_col += 1;
                       break;
                    case 'S':
                       if (curr_row != N-1 && arena[curr_row+1][curr_col] != '#') curr_row += 1;
                       break;
                    case 'O':
                       if (curr_col != 0 && arena[curr_row][curr_col-1] != '#') curr_col -= 1;
                       break;
                    default:
                       break;
                }
                if (arena[curr_row][curr_col] == '*')
                {
                    n_stickers++;
                    arena[curr_row][curr_col] = '.';
                }
            }
        }

        cout << n_stickers << "\n";

    }        

    return 0;
}
