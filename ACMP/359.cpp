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

	long long n;
	cin >> n;

	long long res = (n * n + 1) / 2;

	for (long long deltaSum = 0; deltaSum < res / 10; ) {
		long long delta = res / 10 - deltaSum;
		deltaSum += delta;
		res += delta;
	}

	cout << res;
}