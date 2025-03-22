#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(int eggs, int floors, int drops) {
	long long product = 1, sum = 0;
	for (int i = 1; i <= eggs && sum < floors; i++) {
		product *= drops - i + 1;
		product /= i;
		sum += product;
	}
	return sum >= floors;
}

bool solve(int test) {
	int drops, eggs;
	cin >> drops >> eggs;

	if (!drops && !eggs)
		return 0;

	eggs++;

	int l = 0, r = 1;
	while (can(eggs, r, drops))
		r *= 2;

	while (l + 1 < r) {
		int m = l + (r - l) / 2;
		if (can(eggs, m, drops))
			l = m;
		else
			r = m;
	}

	cout << "Case " << test << ": " << l << "\n";
	return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	for (int test = 1; solve(test); test++);
}