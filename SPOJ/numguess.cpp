#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string ask(long long n) {
	cout << n << endl;
	string ans;
	cin >> ans;
	return ans;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int l, r;
	cin >> l >> r;

	while (1) {
		int m = l + (r - l) / 2;
		string ans = ask(m);
		if (ans == "LOW")
			l = m + 1;
		else if (ans == "HIGH")
			r = m - 1;
		else
			break;
	}
}