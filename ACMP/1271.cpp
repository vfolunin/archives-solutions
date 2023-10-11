#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void draw(int width, int maxStars) {
	for (int dots = width / 2, stars = 1; stars <= maxStars; dots--, stars += 2)
		cout << string(dots, '.') << string(stars, '*') << string(dots, '.') << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	int firstStars, levelCount;
	cin >> firstStars >> levelCount;

	int width = firstStars + (levelCount - 1) * 2;

	for (int level = 0; level < levelCount; level++)
		draw(width, firstStars + level * 2);
}