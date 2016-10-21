#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n,v;
	cin >> n >> v;
	int G[100][100];
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (i == j) {
				G[i][j] = 0;
				continue;
			}
			G[i][j] = 100001;
		}
	} 
	for (int i = 0; i < n; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		G[a][b] = c;
		G[b][a] = c;
	}
	for (int k = 0; k < v; k++) {
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
			}
		}
	}
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			printf("%d %d %d\n",G[i][j],i,j);
		}
	}
	return 0;
}
