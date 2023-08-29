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

	int messageSize, symbolCount, messageCount;
	cin >> messageSize >> symbolCount >> messageCount;

	symbolCount += 10;
	int bits = 1;
	while ((1 << bits) < symbolCount)
		bits++;

	cout << (messageSize * bits + 7) / 8 * messageCount;
}