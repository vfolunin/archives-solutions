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

	double x;
	cin >> x;

	double sum = 0;
	for (int i = 1; 1; i++) {
		sum += 1.0 / (i + 1);
		if (x <= sum) {
			cout << i << " card(s)";
			break;
		}
	}
}