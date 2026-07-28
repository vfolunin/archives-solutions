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

	int size;
	cin >> size;

	long long res = 1;
	for (long long i = size; i > size / 2; i--)
		res *= i;
	res /= size / 2;

	for (long long i = size / 2; i > 0; i--)
		res *= i;
	res /= size / 2;

	cout << res / 2;
}