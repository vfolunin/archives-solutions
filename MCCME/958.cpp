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

	int r11, r12, r21, r22, r;
	cin >> r11 >> r12 >> r21 >> r22 >> r;

	if (r11 < r21) {
		swap(r11, r21);
		swap(r12, r22);
	}

	cout << (r21 <= r12 && r11 <= r || r11 + r21 <= r ? "Yes" : "No");
}