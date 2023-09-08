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

	double a, b, h;
	cin >> a >> b >> h;

	double c = sqrt(a * a / 4 + h * h);
	double d = sqrt(b * b / 4 + h * h);

	cout << fixed << 2 * b * c << " " << a * d + b * c;
}