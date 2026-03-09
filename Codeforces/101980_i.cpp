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

    int size, start, finish, count;
    cin >> size >> start >> finish >> count;

    int inner = (start <= finish ? finish - start + 1 : size - (start - finish - 1));
    int outer = size - inner;

    int res = -1;
    for (int cycles = 0; inner * (cycles + 1) + outer * cycles <= count; cycles++) {
        for (int inner1 = 0, inner2 = inner; inner1 <= inner; inner1++, inner2--) {
            for (int outer1 = 0, outer2 = outer; outer1 <= outer; outer1++, outer2--) {
                int curCount = (inner1 + inner2 * 2) * (cycles + 1) + (outer1 + outer2 * 2) * cycles;
                if (curCount == count || (curCount == count + 1 && inner2))
                    res = max(res, inner2 + outer2);
            }
        }
    }

    cout << res;
}