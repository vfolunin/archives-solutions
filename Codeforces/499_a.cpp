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

	int size, skip;
	cin >> size >> skip;

	int time = 1, res = 0;
	for (int i = 0; i < size; i++) {
		int l, r;
		cin >> l >> r;

		res += (l - time) % skip;
		res += r - l + 1;
		time = r + 1;
	}

	cout << res;
}