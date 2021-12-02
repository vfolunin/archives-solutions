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

    vector<vector<int>> type(size, vector<int>(size));
    for (vector<int> &row : type)
        for (int &x : row)
            cin >> x;

    set<int> collected;
    for (int i = 0; i < 2 * size; i++) {
        int y, x;
        cin >> y >> x;
        collected.insert(type[y - 1][x - 1]);
    }

    cout << collected.size() << "\n";
}