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

	int n, d;
	cin >> n >> d;

	int res = 0;
	for (; n; n /= d)
		res++;

	cout << res;
}