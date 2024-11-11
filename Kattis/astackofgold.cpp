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

	long long sum, count;
	cin >> sum >> count;

	cout << (sum - (count * (count + 1) / 2 * 29260)) / 110;
}