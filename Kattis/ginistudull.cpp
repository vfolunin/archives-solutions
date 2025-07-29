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

	vector<long long> a(size);
	for (long long &value : a)
		cin >> value;

	sort(a.begin(), a.end());

	long long lSum = 0, rSum = 0;
	for (long long value : a)
		rSum += value;

	double num = 0, den = 2 * rSum * a.size();
	for (int i = 0, lCount = 0, rCount = a.size() - 1; i < a.size(); i++, lCount++, rCount--) {
		rSum -= a[i];

		num += lCount * a[i] - lSum;
		num += rSum - rCount * a[i];

		lSum += a[i];
	}

	cout << fixed << num / den;
}