#include<bits/stdc++.h>

using namespace std;

int digitsSum(int n){
    int sum=0;
    while(n){
        sum+=n%10;
        n=n/10;
    }
    return sum;
}

int main(){
    int n;

    while(scanf("%d", &n) && n!=0){
        while(n>9){
            n=digitsSum(n);
        }
        printf("%d\n", n);
    }

    return 0;
}
