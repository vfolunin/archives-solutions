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

	long long num, den;
	cin >> num >> den;

	den = abs(den);

	cout << (num % den + den) % den;
}