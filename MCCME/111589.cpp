#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getDigit(long long size, long long index) {
    if (size == 1)
        return 0;

    if (index * 2 < size)
        return getDigit(size / 2, index);
    else
        return (getDigit(size / 2, index - size / 2) + 1) % 3;
}

int getDigit(long long index) {
    long long size = 1;
    while (size <= index)
        size *= 2;

    return getDigit(size, index);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long index;
    cin >> index;

    cout << getDigit(index - 1);
}