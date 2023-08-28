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

	int a, b;
	cin >> a >> b;

	if (a > b)
		swap(a, b);

	int res = (b - a) * 2;

	if (b <= res)
		cout << res;
	else
		cout << "No";
}