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

	int ax, ay, cx, cy;
	cin >> ax >> ay >> cx >> cy;

	cout << 2 * cx - ax << " " << 2 * cy - ay;
}