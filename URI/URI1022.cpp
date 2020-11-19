#include <bits/stdc++.h>
 
using namespace std;

int gcd(int a, int b){
    if(a<0){
        a = -a;
    }
    if(b<0){
        b = -b;
    }
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}
 
int main() {
 
    int n;
    int N1, D1, N2, D2, D3, N3;
    char op;
    int mdc;

    scanf("%d", &n);
    
    while(n--){
        scanf("%d / %d %c %d / %d", &N1, &D1, &op, &N2, &D2);
        switch(op){
            case '+':
                N3 = N1*D2 + N2*D1;
                D3 = D1*D2;
                mdc = gcd(max(N3, D3), min(N3,D3));
                
                printf("%d/%d = %d/%d\n", N3, D3, N3/mdc, D3/mdc);
                break;
            case '-':
                N3 = N1*D2 - N2*D1;
                D3 = D1*D2;
                mdc = gcd(max(N3, D3), min(N3,D3));
                
                printf("%d/%d = %d/%d\n", N3, D3, N3/mdc, D3/mdc);
                break;
            case '*':
                N3 = N1*N2;
                D3 = D1*D2;
                mdc = gcd(max(N3, D3), min(N3,D3));
                
                printf("%d/%d = %d/%d\n", N3, D3, N3/mdc, D3/mdc);
                break;
            case '/':
                N3 = N1*D2;
                D3 = D1*N2;
                
                mdc = gcd(max(N3, D3), min(N3,D3));
                
                printf("%d/%d = %d/%d\n", N3, D3, N3/mdc, D3/mdc);
                break;
        }
    }
 
    return 0;
}