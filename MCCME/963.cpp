#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(int h, int w, vector<int> &count) {
    for (int count : count)
        w -= count / h;
    return w <= 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, typeCount;
    cin >> size >> typeCount;

    vector<int> count(typeCount);
    for (int &count : count)
        cin >> count;

    int l = 0, r = 1;
    while (can(r, size, count))
        r *= 2;

    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(m, size, count))
            l = m;
        else
            r = m;
    }

    cout << l << "\n";
    for (int type = 0; type < count.size(); type++) {
        int w = count[type] / l;
        for (int i = 0; i < w && size; i++, size--)
            cout << type + 1 << "\n";
    }
}