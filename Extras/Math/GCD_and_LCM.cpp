#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){ b==0 ? a:gcd(b, a%b); }
int lcm(int a, int b){ return a * (b / gcd(a,b)); }

int main(){
	
	return 0;
}