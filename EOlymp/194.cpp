#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string getMin(int n) {
	string res;
	for (int digit = 9; digit > 1; digit--) {
		while (n % digit == 0) {
			res += digit + '0';
			n /= digit;
		}
	}
	return n > 1 ? "-1" : string(res.rbegin(), res.rend());
}

string getMax(int n) {
	string res;
	for (int digit = 2; digit < 10; digit++) {
		while (n % digit == 0) {
			res += digit + '0';
			n /= digit;
		}
	}
	return n > 1 ? "-1" : string(res.rbegin(), res.rend());
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	cout << getMin(n) << " " << getMax(n);
}