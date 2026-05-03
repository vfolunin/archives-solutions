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

    for (int i = 0; i < a.size(); i++) {
        int maxI = max_element(a.begin() + i, a.end()) - a.begin();
        if (maxI != i) {
            swap(a[i], a[maxI]);
            break;
        }
    }

    int maxValue = 0, res = 0;
    for (int value : a) {
        maxValue = max(maxValue, value);
        res += maxValue;
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}