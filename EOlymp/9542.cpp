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

	int n;
	cin >> n;

	string res;
	for (int digit = 2; digit < 10; digit++) {
		while (n % digit == 0) {
			res += digit + '0';
			n /= digit;
		}
	}
	
	cout << (n > 1 ? "-1" : string(res.rbegin(), res.rend()));
}