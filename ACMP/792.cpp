#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(int n, int base) {
	int res = 0;
	while (n >= base) {
		res += n % base;
		n /= base;
	}
	return res + n;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a, baseA, b, baseB;
	cin >> a >> baseA >> b >> baseB;

	int sumA = digitSum(a, baseA), sumB = digitSum(b, baseB);

	cout << (sumA == sumB ? sumA : 0);
}