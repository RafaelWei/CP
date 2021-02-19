#include<bits/stdc++.h>
using namespace std;

char original[10][10];
char transformed[10][10];
int n;

void rotate(){
	char temp[10][10];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			temp[i][j] = original[n-j-1][i];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			original[i][j] = temp[i][j];
		}
	}
}

void reflect(){
	for(int i=0; i<n/2; i++){
		for(int j=0; j<n; j++){
			char temp = original[i][j];
			original[i][j] = original[n-1-i][j];
			original[n-1-i][j] = temp;
		}
	}
}

bool find(){
	bool ok = true;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(original[i][j] != transformed[i][j]){
				ok = false;
				break;
			}
		}
		if(!ok) break;
	}
	return ok;
}

int main(){
	int case_n=1;
	while(scanf("%d", &n)!=EOF){
		for(int i=0; i<n; i++){
			scanf("%s", original[i]);
			scanf("%s", transformed[i]);
		}		
		int cnt = 0;
		if(find()) cnt++;
		else{
			for(int i=2; i<5; i++){
				rotate();
				if(find()) {cnt=i; break;}
			}
			if(cnt==0){
				rotate();
				reflect();
				if(find()){
					cnt=5;
				}
				else{
					for(int i=6; i<9; i++){
						rotate();
						if(find()) {cnt=i; break;}
					}
				}
			}
		}
		switch(cnt){
			case 1:
				printf("Pattern %d was preserved.\n", case_n++);
				break;
			case 2:
				printf("Pattern %d was rotated 90 degrees.\n", case_n++);
				break;
			case 3:
				printf("Pattern %d was rotated 180 degrees.\n", case_n++);
				break;
			case 4:
				printf("Pattern %d was rotated 270 degrees.\n", case_n++);
				break;
			case 5:
				printf("Pattern %d was reflected vertically.\n", case_n++);
				break;
			case 6:
				printf("Pattern %d was reflected vertically and rotated 90 degrees.\n", case_n++);
				break;
			case 7:
				printf("Pattern %d was reflected vertically and rotated 180 degrees.\n", case_n++);
				break;
			case 8:
				printf("Pattern %d was reflected vertically and rotated 270 degrees.\n", case_n++);
				break;
			default:
				printf("Pattern %d was improperly transformed.\n", case_n++);
		
		}
	}
	return 0;
}