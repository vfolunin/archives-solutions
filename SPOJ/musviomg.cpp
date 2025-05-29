#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_map<int, vector<int>> pos;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        pos[value].push_back(i);
    }

    int res = 1e9;
    for (auto &[_, pos] : pos)
        for (int i = 1; i < pos.size(); i++)
            res = min(res, pos[i] - pos[i - 1] + 1);

    cout << (res < 1e9 ? res : -420);
}