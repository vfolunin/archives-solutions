#include <iostream>
#include <algorithm>
#include <cmath>
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

    vector<vector<int>> a(size, vector<int>(3));
    for (vector<int> &row : a)
        for (int &value : row)
            cin >> value;

    sort(a.begin(), a.end(), [](auto &lhs, auto &rhs) {
        return lhs[0] * lhs[1] * lhs[2] < rhs[0] * rhs[1] * rhs[2];
    });

    for (vector<int> &row : a) {
        for (int value : row)
            cout << value << " ";
        cout << "\n";
    }
}