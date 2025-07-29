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

	int n;
	cin >> n;

	if (n % 2)
		cout << (n + 1) / 2 << " " << n / 2;
	else if (n % 4 == 0)
		cout << n / 4 + 1 << " " << n / 4 - 1;
	else
		cout << "impossible";
}