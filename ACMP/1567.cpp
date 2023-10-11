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

	long long size, index;
	cin >> size >> index;

	while (size > 1) {
		if (index % 2) {
			cout << "0 ";
			index = (index + 1) / 2;
			size = (size + 1) / 2;
		} else {
			cout << "1 ";
			index /= 2;
			size /= 2;
		}
	}
}