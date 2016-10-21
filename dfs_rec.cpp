#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int visited[10000];
vector <int> v[100001];
int end;
void dfs(int start) {
	cout << start << "->";
	visited[start] = 1;
	if (start == end) {
		return ;
	}
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
			dfs(i);
			cout << endl;
		}
	}
	return 0;
}




