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

	int size, base;
	cin >> size >> base;

	vector<long long> ways = { 1, base - 1 };
	for (int i = 2; i <= size; i++)
		ways.push_back((base - 1) * (ways[i - 1] + ways[i - 2]));
	ways[1]++;

	cout << ways[size];
}