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

	vector<int> a(3);
	for (int &value : a)
		cin >> value;

	vector<int> b = a;
	sort(b.begin(), b.end());

	int diff = 0;
	for (int i = 0; i < a.size(); i++)
		diff += a[i] != b[i];

	cout << (diff + 1) / 2;
}