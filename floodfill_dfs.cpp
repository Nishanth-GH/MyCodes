#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int visited[100001];
int col[100001];
vector <int> v[100001];
int ct = 0;
void dfs(int start) {
	cout << start << "->";
	visited[start] = 1;
	col[start] = ct;
	for (int i = 0; i < v[start].size(); i++) {
		int val = v[start][i];
		if (!visited[val]) {
			dfs(val);
		}
	}
}
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	int i;
	for (i = 0; i < m; i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			ct++;
			dfs(i);
			cout << endl;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << i << ' ' << col[i] << endl;
	}
	return 0;
}




