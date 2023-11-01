#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;
	cin >> s;

	const long long MOD = 1e9 + 7;
	
	long long sRemainder = 0;
	for (char c : s)
		sRemainder = (sRemainder * 10 + c - '0') % MOD;

	int res = 1;
	long long resRemainder = 1;

	while (sRemainder != resRemainder) {
		res++;
		resRemainder = resRemainder * res % MOD;
	}

	cout << res;
}