#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	int size;
	cin >> size;

	unordered_set<int> nonzeroValues;
	for (int i = 0; i < size; i++) {
		int value;
		cin >> value;

		if (value)
			nonzeroValues.insert(value);
	}

	cout << nonzeroValues.size();
}