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

	double green, red, dist;
	cin >> green >> red >> dist;

	double minTime = 0, maxTime = green;
	while (1) {
		double minSpeed = dist / maxTime;
		double maxSpeed = dist / minTime;

		if (minSpeed <= 1000) {
			cout.precision(9);
			cout << fixed << min(1000.0, maxSpeed);
			return 0;
		}

		minTime = (minTime ? maxTime + red : red);
		maxTime = minTime + green;
	}
}