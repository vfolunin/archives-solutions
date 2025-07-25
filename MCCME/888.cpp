#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("fitness.in", "r", stdin);
    freopen("fitness.out", "w", stdout);

    int size, totalCount, openCount = 0;
    cin >> size >> totalCount;

    for (int i = 0; i < size; i++) {
        int lock, open;
        cin >> lock >> open;

        openCount -= min(openCount, lock);
        openCount = max(openCount, open);
    }

    cout << totalCount - openCount;
}