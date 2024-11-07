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

    vector<vector<int>> res;
    for (int mask = 1; mask < (1 << size); mask++) {
        vector<int> cur;
        for (int i = 0; i < size; i++)
            if (mask & (1 << i))
                cur.push_back(i + 1);
        res.push_back(cur);
    }

    sort(res.begin(), res.end());

    for (vector<int> &cur : res) {
        for (int value : cur)
            cout << value << " ";
        cout << "\n";
    }
}