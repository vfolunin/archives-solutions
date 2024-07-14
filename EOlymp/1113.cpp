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

	long long n, levelCount;
	cin >> n >> levelCount;

	long long res = n;
	for (int i = 2; i <= levelCount; i++)
		res += (n - 2) * i + 1;

	cout << res;
}