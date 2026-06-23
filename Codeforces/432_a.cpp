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

	int size, limit;
	cin >> size >> limit;

	int count = 0;
	for (int i = 0; i < size; i++) {
		int value;
		cin >> value;

		count += value + limit <= 5;
	}

	cout << count / 3;
}