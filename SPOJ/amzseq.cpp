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

	vector<int> ways(3, 1);
	for (int i = 2; i <= size; i++) {
		ways = {
			ways[0] + ways[1],
			ways[0] + ways[1] + ways[2],
			ways[1] + ways[2]
		};
	}

	cout << ways[0] + ways[1] + ways[2];
}