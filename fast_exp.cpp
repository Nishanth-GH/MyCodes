#include <iostream>
#include <cstdio>
#define lli long long int
#define M 1000000007
using namespace std;
lli fast_exp(lli base,lli exp) {
    lli res =1;
    while (exp > 0) {
    	if (exp % 2) {
    		res = (res*base) % M;
		}
        base = (base*base) % M;
        exp /= 2;
    }
    return res;
}
int main() {
	int n,k;
	cin >> n >> k;
	cout << fast_exp(n,k) << endl;
	return 0;
}
