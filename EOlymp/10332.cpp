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

	int vertexCount;
	cin >> vertexCount;

	vector<int> degree(vertexCount);
	for (int i = 0; i < vertexCount - 1; i++) {
		int a, b;
		cin >> a >> b;

		degree[a - 1]++;
		degree[b - 1]++;
	}

	cout << *max_element(degree.begin(), degree.end()) + 1;
}