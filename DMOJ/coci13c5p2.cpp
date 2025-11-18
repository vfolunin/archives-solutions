#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int level, vector<vector<int>> &res) {
    if (level == res.size())
        return;

    rec(level + 1, res);
    cin >> res[level].emplace_back();
    rec(level + 1, res);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<vector<int>> res(size);
    rec(0, res);

    for (vector<int> &row : res) {
        for (int value : row)
            cout << value << " ";
        cout << "\n";
    }
}