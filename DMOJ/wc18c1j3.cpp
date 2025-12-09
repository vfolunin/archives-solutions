#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

char getMark(int score) {
	if (score >= 90)
		return 'A';
	else if (score >= 80)
		return 'B';
	else if (score >= 70)
		return 'C';
	else if (score >= 60)
		return 'D';
	else
		return 'F';
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a, b;
	cin >> a >> b;

	cout << (getMark(a) == getMark(b) ? "Same" : "Different");
}