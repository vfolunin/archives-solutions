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

    vector<int> res, negative;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value >= 0)
            res.push_back(value);
        else
            negative.push_back(value);
    }

    sort(negative.begin(), negative.end());
    for (int l = 0, r = (int)negative.size() - 1; l <= r; ) {
        res.push_back(negative[r--]);
        for (int i = 0; i < 2 && l <= r; i++, l++)
            res.push_back(negative[l]);
    }

    for (int value : res)
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