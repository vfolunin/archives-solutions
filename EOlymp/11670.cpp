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

    long long size, index;
    cin >> size >> index;

    long long y = index / size;
    long long x = index % size;

    long long res = 0;
    if (y)
        res += (y - 1) * size + x;
    if (y + 1 < size)
        res += (y + 1) * size + x;
    if (x)
        res += y * size + x - 1;
    if (x + 1 < size)
        res += y * size + x + 1;

    cout << res;
}