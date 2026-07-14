#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, delta;
    cin >> size >> delta;

    int res = 0;
    vector<int> negative;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value >= 0)
            res += value;
        else
            negative.push_back(value);
    }

    sort(negative.begin(), negative.end());
    for (int i = 0; i < negative.size() && -negative[i] > (i + 1) * delta; i++)
        res += -negative[i] - (i + 1) * delta;

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