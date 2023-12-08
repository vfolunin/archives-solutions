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

	double ab, bc, ac;
	cin >> ab >> bc >> ac;

	cout << fixed << (ab + ac - bc) / 2 << " ";
	cout << fixed << (ab + bc - ac) / 2 << " ";
	cout << fixed << (bc + ac - ab) / 2;
}