#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
	int seqSize;
	if (!(cin >> seqSize))
		return 0;

	vector<int> seq(seqSize);
	for (int &x : seq)
		cin >> x;

	cout << "Case #" << test << ":";
	for (int x : seq)
		cout << " " << x;
	cout << "\n";

	vector<int> canMake(30001);
	canMake[0] = 1;

	for (int i = 0; i < seqSize; i++) {
		if (!i && seq[i] < 1 || i && seq[i] <= seq[i - 1] || canMake[seq[i]]) {
			cout << "This is not an A-sequence.\n";
			return 1;
		}
		for (int sum = 30000; sum >= seq[i]; sum--)
			if (canMake[sum - seq[i]])
				canMake[sum] = 1;
	}

	cout << "This is an A-sequence.\n";
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	for (int test = 1; solve(test); test++);
}