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

    int size, symbolCount, userCount;
    cin >> size >> symbolCount >> userCount;

    symbolCount = symbolCount * 2 + 10;
    int symbolBitCount = bit_width((unsigned)symbolCount - 1);
    int passwordByteCount = (symbolBitCount * size + 7) / 8;

    cout << passwordByteCount * userCount;
}