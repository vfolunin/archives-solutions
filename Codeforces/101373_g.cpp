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

	if (size >= 5)
		cout << string(size - 4, '3') << "1224";
	else
		cout << "impossible";
}