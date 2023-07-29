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

	int a = n / 144;
	int b = n % 144 / 12;
	int c = n % 12;

	if (c * 105 > 1025) {
		b++;
		c = 0;
	}
	if (b * 1025 + c * 105 > 11400) {
		a++;
		b = c = 0;
	}

	cout << a << " " << b << " " << c;
}