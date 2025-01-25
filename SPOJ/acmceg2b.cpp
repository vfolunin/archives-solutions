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

	map<pair<int, int>, string> name;
	for (int i = 0; i < size; i++) {
		int a, b;
		cin >> a >> b >> name[{ a, b }];
	}

	int queryCount;
	cin >> queryCount;

	for (int i = 0; i < queryCount; i++) {
		int a, b;
		cin >> a >> b;

		cout << name[{ a, b }] << "\n";
	}
}