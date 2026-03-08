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

    long long size, count;
    cin >> size >> count;

    count = min(count + 1, size);
    long long gapCount = size - count;
    long long maxGap = (gapCount + count - 1) / count;

    cout << size - maxGap;
}