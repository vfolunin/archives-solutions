#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int size, int limit, vector<int> &used, vector<int> &res) {
    if (res.size() == size) {
        for (int value : res)
            cout << value + 1 << " ";
        cout << "\n";
        return;
    }

    for (int value = 0; value < limit; value++) {
        if (!used[value]) {
            used[value] = 1;
            res.push_back(value);
            rec(size, limit, used, res);
            used[value] = 0;
            res.pop_back();
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int limit, size;
    cin >> limit >> size;

    vector<int> used(limit), res;
    rec(size, limit, used, res);
}