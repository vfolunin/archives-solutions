#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
	int size;
	cin >> size;

	if (size % 2) {
		for (int i = 0; i < size; i++)
			cout << "1 ";
	} else {
		for (int i = 0; i < size - 2; i++)
			cout << "2 ";
		cout << "1 3";
	}
	cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}