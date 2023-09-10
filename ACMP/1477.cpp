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

	int h, w;
	cin >> h >> w;
	if (h > w)
		swap(h, w);

	if (h == w && h % 2 == 0)
		cout << 4;
	else if (h * 3 == w)
		cout << 3;
	else if (h == w && h > 1 || h * 2 <= w || h % 2 == 0 || w % 2 == 0 && h >= w / 2)
		cout << 2;
	else
		cout << 1;
}