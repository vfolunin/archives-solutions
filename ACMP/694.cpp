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

    int segmentCount;
    cin >> segmentCount;

    int l = 1, r = 31;
    for (int i = 0; i < segmentCount; i++) {
        int curL, curR;
        cin >> curL >> curR;
        l = max(l, curL);
        r = min(r, curR);
    }

    cout << (l <= r ? "YES" : "NO");
}