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

	int size, type;
	cin >> size >> type;

	vector<int> count(4);
	count[1] = 6 * (size - 2) * (size - 2);
	count[2] = 12 * (size - 2);
	count[3] = 8;
	count[0] = size * size * size - count[1] - count[2] - count[3];

	cout << count[type];
}