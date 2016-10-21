#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
void knapsack(int p[],int w[],int n,int k) {
	int i,j;
	int dp[n+1][k+1];
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= k; j++) {
			dp[i][j] = 0;
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= k; j++) {
			if (j >= w[i-1]) {
				dp[i][j] = max(dp[i-1][j],p[i-1]+dp[i-1][j-w[i-1]]);
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	printf("%d\n",dp[n][k]);
}
int main() {
	int n,k;
	scanf("%d %d",&n,&k);
	int i,w[n],p[n],j;
	for (i = 0; i < n; i++) {
		scanf("%d",&w[i]);
	}
	for (i = 0; i < n; i++) {
		scanf("%d",&p[i]);
	}
	knapsack(p,w,n,k);
	return 0;
}
