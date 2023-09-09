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

	int h, w, size;
	cin >> h >> w >> size;

	for (int y = 0; y < h * size; y++) {
		for (int x = 0; x < w * size; x++)
			cout << ((y / size + x / size) % 2 == h % 2 ? '.' : 'X');
		cout << "\n";
	}
}