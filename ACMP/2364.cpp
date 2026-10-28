#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <bit>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int symbolCount, userCount, totalSize;
    cin >> symbolCount >> userCount >> totalSize;

    symbolCount += 62;
    totalSize *= 1024;
    int symbolBitCount = bit_width((unsigned)symbolCount - 1);
    int passwordBitCount = totalSize / userCount * 8;

    cout << passwordBitCount / symbolBitCount;
}