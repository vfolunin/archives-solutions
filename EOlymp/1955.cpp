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

	int d1, m1, y1, d2, m2, y2;
	cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;

	cout << y2 - y1 - (m2 < m1 || m2 == m1 && d2 < d1);
}