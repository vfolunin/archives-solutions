#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int h, int w) {
    if (!h || !w)
        return 0;

    int size = 1;
    while (size * 2 <= h && size * 2 <= w)
        size *= 2;

    return 1 + rec(size, w - size) + rec(h - size, size) + rec(h - size, w - size);
}

bool solve() {
	int h, w;
    if (!(cin >> h >> w))
	    return 0;

	cout << rec(h, w) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	while (solve());
}