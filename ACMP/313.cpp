#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int busCount;
    cin >> busCount;

    unordered_map<int, int> last;
    int res = 0;

    for (int i = 0; i < busCount; i++) {
        int bus;
        cin >> bus;

        if (last.count(bus))
            res = max(res, i - last[bus]);

        last[bus] = i;
    }

    cout << res;
}