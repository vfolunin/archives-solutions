#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	double a, b, radius;
	cin >> a >> b >> radius;

	double xl = 0, xr = radius;
	for (int i = 0; i < 100; i++) {
		double x1 = xl + (xr - xl) / 3;
		double y1 = sqrt(radius * radius - x1 * x1);

		double x2 = xr - (xr - xl) / 3;
		double y2 = sqrt(radius * radius - x2 * x2);

		if (a * x1 + b * y1 < a * x2 + b * y2)
			xl = x1;
		else
			xr = x2;
	}
	double yl = sqrt(radius * radius - xl * xl);

	cout << fixed << a * xl + b * yl << "\n" << xl << " " << yl;
}