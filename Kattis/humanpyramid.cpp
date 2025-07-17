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

	long long limit;
	cin >> limit;

	int res = 0;
	long long sum = 0;

	while (sum + res + 1 <= limit) {
		res++;
		sum += res;
	}

	cout << res;
}