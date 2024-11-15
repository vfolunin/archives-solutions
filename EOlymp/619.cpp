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

    vector<vector<int>> pos(4);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        pos[value - 1].push_back(i);
    }

    int res = 1e9;
    for (vector<int> &pos : pos) {
        pos.push_back(size + pos[0]);
        for (int i = 0; i + 1 < pos.size(); i++)
            res = min(res, size - (pos[i + 1] - pos[i] - 1));
    }

    cout << res;
}