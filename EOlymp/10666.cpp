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

	map<string, int> salary;

	string name;
	int delta;
	while (cin >> name >> delta)
		salary[name] += delta;

	for (auto &[name, salary] : salary)
		cout << name << " " << salary << "\n";
}