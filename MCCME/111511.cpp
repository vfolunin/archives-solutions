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

    int size, usedCount;
    cin >> size >> usedCount;

    size *= 4;
    vector<int> used(size + 1);
    for (int i = 0; i < usedCount; i++) {
        int index;
        cin >> index;
        used[index] = 1;
    }

    for (int i = 1; i <= size; i += 2) {
        if (!used[i] && !used[i + 1]) {
            cout << i << " " << i + 1;
            return 0;
        }
    }

    for (int i = 1; i <= size; i += 4) {
        if (!used[i + 1] && !used[i + 3]) {
            cout << i + 1 << " " << i + 3;
            return 0;
        }
    }

    cout << find(used.begin() + 1, used.end(), 0) - used.begin() << " ";
    cout << used.rend() - find(used.rbegin(), used.rend(), 0) - 1;
}