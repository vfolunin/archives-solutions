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

	int red = 0, green = 0, blue = 0;
	for (int y = 1; y <= h; y++) {
		for (int x = 1; x <= w; x++) {
			int value = y * x;
			if (value % 5 == 0)
				blue++;
			else if (value % 3 == 0)
				green++;
			else if (value % 2 == 0)
				red++;
		}
	}

	cout << "RED : " << red << "\n";
	cout << "GREEN : " << green << "\n";
	cout << "BLUE : " << blue << "\n";
	cout << "BLACK : " << h * w - red - green - blue;
}