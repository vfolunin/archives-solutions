#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void stepRight() {
	cout << "DOWN\nRIGHT\nUP\n";
}

void markColumn(int h) {
	for (int i = 0; i < h - 1; i++)
		cout << "RIGHT\nDOWN\nLEFT\n";
	for (int i = 0; i < h - 1; i++)
		cout << "RIGHT\nUP\nLEFT\n";
}

void markLastColumn(int h) {
	for (int i = 0; i < h - 1; i++)
		cout << "LEFT\nDOWN\nRIGHT\n";
	for (int i = 0; i < h - 1; i++)
		cout << "LEFT\nUP\nRIGHT\n";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int h, w;
	cin >> h >> w;

	if (h == 1) {
		cout << (w == 1 ? "" : "no solution");
	} else if (w == 1) {
		cout << (h == 2 ? "DOWN\nUP\n" : "no solution");
	} else {
		for (int i = 0; i < w - 1; i++) {
			markColumn(h);
			stepRight();
		}
		markLastColumn(h);
	}
}