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

	int n;
	cin >> n;

	long long sum = 0;
	for (int i = 0; i < n; i++) {
		char type;
		int outL, outR, inL, inR;
		cin >> type >> outL >> outR >> inL >> inR;

		sum += inL;
		sum -= outR;

		if (type == 'B')
			cout << sum << " ";
		else
			cout << "-1 ";

		sum += inR;
		sum -= outL;
	}
}