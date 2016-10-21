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
using namespace std;
#define lli long long int
#define M 1000000007
#define INF 1000000009
#define rep(i, a, b)  for (int i = int(a); i < int(b); i++)
#define nrep(i, a, b)  for (int i = int(a); i < int(b); i--)
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

template<typename P> struct Cmp
{
    bool operator()(const P &p1, const P &p2)
    {
    	if (p1.first > p2.first) return true;
    	if (p1.first == p2.first) return p1.second < p2.second;
        return false;
    }
};
int main() {
	int n;
	cin >> n;
	int a[n];
	rep(i, 0, n) {
		sc(a[i]);
	}   
	int I[n+1],L[n];
	rep(i, 0, n+1) {
		I[i] = INF;
		if (!i) I[i] = -INF;
	}
	rep(i, 0, n) {
		L[i] = -1;
	}
	rep(i, 0, n) {
		rep(j, 0, n+1) {
			if (a[i] <= I[j]) {
				I[j] = a[i];
				L[i] = j;
				break;
			} 
		}
	}
	int max = 0;
	rep(i, 0, n) {
		if (L[i] > max) {
			max = L[i];
		}
	}
	cout << max << endl;
	return 0;
}

