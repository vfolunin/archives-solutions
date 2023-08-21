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

	long long size, h, w;
	cin >> size >> h >> w;

	cout << ((h + size - 1) / size + 1) * ((w + size - 1) / size + 1);
}