#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end(), [](int l, int r) {
        if (l % 2 != r % 2)
            return l % 2 != 0;
        if (l % 2)
            return l % 3 == 0 && r % 3;
        return l % 3 && r % 3 == 0;
    });

    for (int value : a)
        cout << value << " ";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}