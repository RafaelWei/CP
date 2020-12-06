#include<bits/stdc++.h>

using namespace std;

int sol;

void imprimirTabuleiro(const vector< vector<int> >& tab){
    for(int i=0; i<tab.size(); i++){
        for(int j=0; j<tab.size(); j++){
            if(tab[i][j] == 1){
                printf("R ");
            }
            else{
                printf("- ");
            }
        }
        printf("\n");
    }
}

bool podeColocar(const vector< vector<int> >& tab, int line, int col){
    ///Checa a linha
    for(int i=0; i<8; i++){
        if(tab[line][i] == 1){
            return false;
        }
    }

    ///Checa a coluna
    for(int i=0; i<8; i++){
        if(tab[i][col] == 1){
            return false;
        }
    }

    ///Checa a diagonal principal
    for(int i=line, j = col; i>=0 && j>=0; i--, j--){
        if(tab[i][j] == 1){
            return false;
        }
    }
    for(int i=line, j = col; i<8 && j<8; i++, j++){
        if(tab[i][j] == 1){
            return false;
        }
    }
    ///Checa a diagonal secundaria
    for(int i=line, j = col; i<8 && j>=0; i++, j--){
        if(tab[i][j] == 1){
            return false;
        }
    }
    for(int i=line, j = col; i>=0 && j<8; i--, j++){
        if(tab[i][j] == 1){
            return false;
        }
    }

    return true;
}

void solveQueensProblem(vector< vector<int> >& tab, int tabSize, int line){
    if(line == 8){
        printf("Solucao %d:\n", sol+1);
        imprimirTabuleiro(tab);
        sol++;
        return;
    }

    for(int j=0; j<8; j++){
        if(podeColocar(tab, line, j)){
            tab[line][j] = 1;

            solveQueensProblem(tab, 8, line + 1);

            tab[line][j] = 0;
        }
    }
}

int main(){
    vector< vector<int> > tab;

    for(int i=0; i<8; i++){
        vector<int> vec(8);
        tab.push_back(vec);
    }

    solveQueensProblem(tab, 8, 0);

    return 0;
}
