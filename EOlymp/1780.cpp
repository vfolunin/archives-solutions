#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long grayCode(int size, long long index) {
    if (!size)
        return 0;

    long long half = 1LL << (size - 1);
    if (index < half)
        return grayCode(size - 1, index);
    else
        return half + grayCode(size - 1, half - 1 - (index - half));
}

bool solve() {
    long long index;
    if (!(cin >> index))
        return 0;

    cout << grayCode(60, index) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}