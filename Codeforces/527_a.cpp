#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(long long a, long long b) {
	return b ? rec(b, a % b) + a / b : 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	long long h, w;
	cin >> h >> w;

	cout << rec(h, w);
}