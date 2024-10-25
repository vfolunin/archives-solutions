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

    int count, from;
    cin >> count >> from;

    int res = 0;
    for (int size = 1, to = 1; count; size++) {
        to *= 10;
        if (to > from) {
            int curCount = min(count, to - from);
            count -= curCount;
            res += curCount * size;
            from += curCount;
        }
    }

    cout << res;
}