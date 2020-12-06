#include<bits/stdc++.h>

using namespace std;

const int maxTime = 60*60;

bool allGreen(int time, const vector<int>& timings){
    for(int i=0; i<timings.size(); i++){
        if(time%(timings[i]*2) >= timings[i]-5){
            return false;
        }
    }
    return true;
}

int main(){
    int t=1;
    string syncs;

    while(getline(cin, syncs)){
        stringstream ss(syncs);

        vector<int> timings;
        int minTime = 90;
        int time;

        while(ss>>time){
            timings.push_back(time);
            if(time < minTime) minTime = time;
        }

        int currTime = 2*minTime;

        while(!allGreen(currTime, timings) && currTime <= maxTime){
            currTime++;
        }

        if(currTime > maxTime){
            printf("Set %d is unable to synch after one hour.\n", t);
        }
        else{
            printf("Set %d synchs again at %d minute(s) and %d second(s) after all turning green.\n", t, currTime/60, currTime%60);
        }
        t++;
    }

    return 0;
}
