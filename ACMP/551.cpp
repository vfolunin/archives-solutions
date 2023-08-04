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

	int bigRadius, smallRadius, height, dist;
	cin >> bigRadius >> smallRadius >> height >> dist;

	int x = -dist + smallRadius + height, y = smallRadius;
	
	cout << (x * x + y * y <= bigRadius * bigRadius ? "YES" : "NO");
}