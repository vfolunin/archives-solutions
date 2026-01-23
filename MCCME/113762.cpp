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

	long long emptyCount, sum;
	cin >> emptyCount >> sum;

	long long textCount = 0, textSum = 0;
	while (textSum < sum) {
		textCount++;
		textSum += emptyCount + textCount;
	}

	if (textSum == sum) {
		cout << emptyCount;
		return 0;
	}

	textSum -= emptyCount + textCount;
	textCount--;

	emptyCount += (sum - textSum + textCount - 1) / textCount;
	cout << emptyCount;
}