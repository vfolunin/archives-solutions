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

	int x, y, moveCount;
	cin >> x >> y >> moveCount;

	x = abs(x);
	y = abs(y);

	if (x + y > moveCount || (moveCount - x - y) % 2)
		cout << "NO";
	else
		cout << "YES";
}