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

    vector<int> a(size);
    int xorSum = 0;

    for (int &value : a) {
        cin >> value;
        xorSum ^= value;
    }

    vector<pair<int, int>> res;
    if (xorSum) {
        for (int i = 0; i < size; i++) {
            int curSum = xorSum ^ a[i];
            if (curSum < a[i])
                res.push_back({ i + 1, a[i] - curSum });
        }
    }

    cout << (xorSum ? 1 : 2) << "\n";
    if (xorSum) {
        cout << res.size() << "\n";
        for (auto &[index, value] : res)
            cout << index << " " << value << "\n";
    }
}