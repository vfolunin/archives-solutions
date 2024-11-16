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

	double ab, ac, ad, bc, bd, cd;
	cin >> ab >> ac >> ad >> bc >> bd >> cd;

	double ax = 0, ay = 0, az = 0;
	double bx = ab, by = 0, bz = 0;

	double cx = (bc * bc - ac * ac - bx * bx) / (-2 * bx);
	double cy = sqrt(ac * ac - cx * cx);
	double cz = 0;

	double dx = (bd * bd - ad * ad - bx * bx) / (-2 * bx);
	double dy = (cd * cd - ad * ad - cx * cx - cy * cy + 2 * dx * cx) / (-2 * cy);
	double dz = sqrt(ad * ad - dx * dx - dy * dy);

	cout << fixed << bx * cy * dz / 6;
}