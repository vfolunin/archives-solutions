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

	int size, sum;
	cin >> size >> sum;

	sum = abs(sum);
	int res = 1e9;

	for (int i = 0; i < size; i++) {
		int value;
		cin >> value;

		if (sum % value == 0)
			res = min(res, sum / value);
	}

	if (res != 1e9)
		cout << res;
	else
		cout << "This is not the best time for a trip.";
}