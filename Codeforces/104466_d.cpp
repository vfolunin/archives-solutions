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

    vector<int> maxValue = { 4, 6, 8, 12, 20 };
    int l = 0, r = 0;

    for (int value : maxValue) {
        int count;
        cin >> count;

        l += count;
        r += count * value;
    }

    vector<int> res;
    for (; l <= r; l++, r--) {
        res.push_back(l);
        if (l < r)
            res.push_back(r);
    }
    reverse(res.begin(), res.end());

    for (int value : res)
        cout << value << " ";
}