#include<bits/stdc++.h>
using namespace std;

int blocks[25][25];
int height[25] = {1};
int n;

bool invalidMove(int a, int b){
	if(a==b) return true;
	for(int i=0; i<height[a]; i++){
		if(blocks[a][i]==b) return true;
	}
	for(int i=0; i<height[b]; i++){
		if(blocks[b][i]==a) return true;
	}
}

pair<int,int> find(int x){
	for(int i=0; i<n; i++){
		for(int j=0; j<height[i]; j++){
			if(blocks[i][j]==x){
				return make_pair(i,j);
			}
		}
	}
}

int main(){
	int origin, dest;
	char cmd1[10];
	char cmd2[10];

	scanf("%d", &n);
	while(scanf("%s", cmd1)){
		if(strcmp(cmd1, "quit")){
			break;
		}
		else if(strcmp(cmd1, "move")){
			scanf("%d %s %d", &origin, cmd2, &dest);
			if(strcmp(cmd2, "onto")){
				if(invalidMove(origin, dest)) continue;
				pair<int,int> pa = find(origin);
				pair<int,int> pb = find(dest);
				for(int i=pa.second+1; i<height[pa.first]; i++){
					blocks[blocks[pa.first][i]][0] = blocks[pa.first][i];
					height[blocks[pa.first][i]] = 1;
				}
			}
			else if(strcmp(cmd2, "over")){
				if(invalidMove(origin, dest)) continue;
			}
		}
		else if(strcmp(cmd1, "pile")){
			scanf("%d %s %d", &origin, cmd2, &dest);
			if(strcmp(cmd2, "over")){

			}
			else if(strcmp(cmd2, "onto")){

			}
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<height[i]l j++){
			printf("")
		}
	}
	return 0;
}