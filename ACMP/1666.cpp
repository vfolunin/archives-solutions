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

	long long l = -1e18, r = 1e18;
	while (1) {
		long long m = l + (r - l) / 2;
		string ans = ask(m);
		if (ans == "Smaller")
			l = m + 1;
		else if (ans == "Greater")
			r = m - 1;
		else
			break;
	}
}