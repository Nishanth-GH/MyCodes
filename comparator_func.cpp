#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define lli long long int
#define M 1000000007
#define INF 1000000009
#define rep(i, a, b)  for (int i = int(a); i < int(b); i++)
#define nrep(i, a, b)  for (int i = int(a)-1; i >= int(b); i--)
#define sc(i) scanf("%d",&i)
#define di(i) printf("%d\n",i)
#define dii(i, j) printf("%d %d\n",i,j)
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <ii> vii;
typedef map <int,int> mi;
typedef map <ii,int> mii;

lli gcd(lli a,lli b) {
	if (b == 0) return a;
	return(a % b == 0 ? b : gcd(b, a % b)); 
}
struct Cmp {
	bool operator() (ii const& p1, ii const& p2) {
		if (p1.first == p2.first) {
			return p1.second > p2.second;
		}
		else {
			return p1.first > p2.first;
		}
	}
};
int main() {
	int n,x,y;
	cin >> n;
	vii v1;
	rep(i, 0, n) {
		cin >> x >> y;
		v1.push_back(ii(x,y));
	}
	sort(v1.begin(),v1.end(), Cmp());
	rep(i, 0, n) {
		cout << v1[i].first << ' ' << v1[i].second << endl;
	}
	return 0;
}

