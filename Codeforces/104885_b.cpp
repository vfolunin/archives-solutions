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

    int maxSize, digitCount;
    cin >> maxSize >> digitCount;

    long long count = 1, res = 0;
    for (int size = 1; size <= maxSize; size++) {
        count *= digitCount;
        res += count;
    }

    cout << res;
}