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

    string digits;
    cin >> digits;

    vector<int> digitCount(10);
    for (char digit : digits)
        digitCount[digit - '0']++;

    int minNonZeroDigit = min_element(digitCount.begin() + 1, digitCount.end()) - digitCount.begin();
    if (digitCount[0] < digitCount[minNonZeroDigit])
        cout << "1" << string(digitCount[0] + 1, '0');
    else
        cout << string(digitCount[minNonZeroDigit] + 1, minNonZeroDigit + '0');
}