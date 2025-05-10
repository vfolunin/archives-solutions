#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, limit;
    cin >> size >> limit;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> parts(1, 1);
    for (int i = 1; i < a.size(); i++) {
        if (a[i - 1] < a[i])
            parts.back()++;
        else
            parts.push_back(1);
    }

    int res = 0;
    for (int value : parts)
        res += max(value - limit + 1, 0);

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
        solve();
}