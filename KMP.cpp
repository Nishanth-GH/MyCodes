#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int pmt[100001];
int main() {
	string s1,s2;
	cin >> s1 >> s2;
	int i = 1,j = 0;
	memset(pmt,0,sizeof(pmt));
	while (i < s2.length()) {
		if (s2[i] == s2[j]) {
			pmt[i] = j+1;
			i++,j++;
		}
		else if (j > 0) {
			j = pmt[j-1];
		}
		else {
			pmt[j] = 0;
			i++;
		}
	}
	i = 0;
	while (i < s1.length()) {
		int ct = 0;
		int k = i;
		for (int j = 0; j < s2.length(); j++) {
			if (s1[k] == s2[j]) {
				k++;
				ct++;
				continue;
			}
			else if (s1[k] != s2[j]) {
				if (pmt[ct] > 1) {
					i = i + (ct - pmt[ct-1]);
				    break;
				}
				else {
					i++;
					break;
				}
			}
		}
		if (ct == s2.length()) {
			cout << i << endl;
			puts("Match Found");
			return 0;
		}
		//cout << ct << ' ' << s2.length() << endl;
	}
	return 0;
}
