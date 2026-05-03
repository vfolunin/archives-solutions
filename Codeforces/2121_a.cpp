#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, startPos;
    cin >> size >> startPos;

    int minPos = 1e9, maxPos = -1e9;
    for (int i = 0; i < size; i++) {
        int pos;
        cin >> pos;

        minPos = min(minPos, pos);
        maxPos = max(maxPos, pos);
    }

    if (startPos <= minPos)
        cout << maxPos - startPos << "\n";
    else if (maxPos <= startPos)
        cout << startPos - minPos << "\n";
    else
        cout << min(startPos - minPos, maxPos - startPos) + maxPos - minPos << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}