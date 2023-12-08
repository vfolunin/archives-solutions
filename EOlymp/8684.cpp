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

	int count = 0, sum = 0;

	for (int value; cin >> value; ) {
		count++;
		sum += value;
	}

	cout << count << " " << sum;
}