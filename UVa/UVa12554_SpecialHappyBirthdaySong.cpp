#include<bits/stdc++.h>
#define SONG_SIZE 16

using namespace std;

string song[] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

int main(){
    int n;
    int pCnt=0, sCnt=0;
    string names[100];
    bool allSing=false;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> names[i];
    }

    while(!allSing){
        cout << names[pCnt] << ": " << song[sCnt] << "\n";
        pCnt = (pCnt+1)%n;
        sCnt = (sCnt+1)%SONG_SIZE;
        if(pCnt==0) allSing=true;
    }

    while(sCnt!=0){
        cout << names[pCnt] << ": " << song[sCnt] << "\n";
        pCnt = (pCnt+1)%n;
        sCnt = (sCnt+1)%SONG_SIZE;
    }

    return 0;
}
