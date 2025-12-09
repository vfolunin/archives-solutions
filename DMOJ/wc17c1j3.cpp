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

	vector<int> res(2);
	while (res[0] < 4 && res[1] < 4) {
		int a, b;
		cin >> a >> b;

		res[0] += a > b;
		res[1] += a < b;
	}

	cout << res[0] << " " << res[1];
}