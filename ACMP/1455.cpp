#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ask(int n) {
	cout << "? " << n << endl;
	int ans;
	cin >> ans;
	return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	int ones = ask(0);

	int res = 0;
	for (int bit = 0; bit < 16; bit++) 
		if (ask(1 << bit) < ones)
			res |= 1 << bit;

	cout << "! " << res << endl;
}