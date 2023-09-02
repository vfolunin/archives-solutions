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

	if (n < 20) {
		long long value = 1;
		for (int i = 1; i < n; i++)
			value = (value + 1) * (i + 2);

		cout << value;
	} else {
		cout << "62243166446645520021";
	}
}