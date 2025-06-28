#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<vector<int>> res(size, vector<int>(size));
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            unordered_set<int> values;
            for (int i = 0; i < y; i++)
                values.insert(res[i][x]);
            for (int i = 0; i < x; i++)
                values.insert(res[y][i]);

            while (values.count(res[y][x]))
                res[y][x]++;

            cout << res[y][x] << " ";
        }
        cout << "\n";
    }
}