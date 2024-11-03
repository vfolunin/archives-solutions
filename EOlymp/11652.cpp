#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(int n) {
	int sum = 0;
	while (n) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int targetSum;
	cin >> targetSum;

	int res = 0;
	for (int i = 1e3; i < 1e4; i++)
		res += digitSum(i) == targetSum;

	cout << res;
}