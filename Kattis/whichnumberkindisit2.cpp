#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int value;
    cin >> value;

    bool found = 0;

    if (value % 2) {
        cout << "O";
        found = 1;
    }

    if (int root = sqrt(value); root * root == value) {
        cout << "S";
        found = 1;
    }

    if (!found)
        cout << "EMPTY";

    cout << "\n";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}