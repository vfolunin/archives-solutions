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

	int size;
	cin >> size;

	int last = 0;
	for (int i = 0; i < size; i++) {
		int m, s;
		cin >> m >> s;

		int time = m * 60 + s;

		if (last + 5 < time) {
			cout << (last + 5) / 60 << " " << (last + 5) % 60;
			return 0;
		}

		last = time;
	}

	cout << 0;
}