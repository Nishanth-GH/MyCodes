#include <iostream>
#include <cstdio>
using namespace std;
int n = 2000001;
int count[2000001];
int a[1000001];
int d = 0;
void sieve() {
	int p = 2;
	while (p <= n) {
		a[d++] = p;
		for (int i = 2; p*i < n; i++) {
			count[p*i] = 1;
		}
		int i;
		for (i = p+1; i < n; i++) {
			if (count[i] == 0) {
				p = i;
				break;
			}
		}
		if (i == n) {
			break;
		}
	}
}
int main() {
	sieve();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}
