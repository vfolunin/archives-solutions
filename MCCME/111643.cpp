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

    int size;
    cin >> size;

    vector<int> res(3, -1);
    int from = -1, count = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value < 5) {
            if (from == -1)
                from = i;
            count += 5 - value;
        } else if (from != -1) {
            if (res.back() < count)
                res = { { from, i - 1, count } };

            from = -1;
            count = 0;
        }
    }

    if (res.back() < count)
        res = { { from, size - 1, count } };

    cout << res[0] + 1 << " " << res[1] + 1 << " " << res[2];
}