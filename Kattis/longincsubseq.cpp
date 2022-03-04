#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size;
    if (!(cin >> size))
        return 0;

    vector<int> a(size);
    vector<int> prevIndex(size, -1);

    vector<int> lastIndex(size + 1, -1);
    int lisSize = 1;

    for (int i = 0; i < size; i++) {
        cin >> a[i];

        int l = 0, r = lisSize + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (lastIndex[m] != -1 && a[lastIndex[m]] < a[i])
                l = m;
            else
                r = m;
        }

        lastIndex[r] = i;
        prevIndex[i] = lastIndex[r - 1];
        lisSize += lisSize < r;
    }

    vector<int> lis;
    for (int i = lastIndex[lisSize]; i != -1; i = prevIndex[i])
        lis.push_back(i);
    reverse(lis.begin(), lis.end());

    cout << lis.size() << "\n";
    for (int i : lis)
        cout << i << " ";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}