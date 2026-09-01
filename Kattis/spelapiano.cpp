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

    int keyCount, changeCount;
    cin >> keyCount >> changeCount;
    changeCount--;

    int cur = 0, l = 0, r = 0;
    for (int i = 0; i < changeCount; i++) {
        int change;
        cin >> change;

        cur += change;
        l = min(l, cur);
        r = max(r, cur);
    }

    if (r - l + 1 <= keyCount)
        cout << 1 - l;
    else
        cout << "finns ingen";
}