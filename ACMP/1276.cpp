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

	vector<pair<int, int>> blocks;
	for (int i = 0; i < size; i++) {
		int value;
		cin >> value;

		if (blocks.empty() || blocks.back().first != value)
			blocks.push_back({ value, 1 });
		else
			blocks.back().second++;
	}

	cout << blocks.size() << " ";
	for (auto &[value, count] : blocks)
		cout << "[" << value << " " << count << "] ";
}