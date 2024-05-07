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

    unordered_map<int, int> count;
    vector<vector<int>> res(2);

    for (int i = 0; i <= size; i++) {
        unordered_map<int, int> nextCount;
        for (int j = 0; j < size - i; j++) {
            int value;
            cin >> value;

            nextCount[value]++;
        }

        if (i) {
            for (auto &[value, count] : count) {
                if (!nextCount.count(value) || count != nextCount[value]) {
                    res[(i - 1) % 2].push_back(value);
                    break;
                }
            }
        }

        count.swap(nextCount);
    }
    
    for (vector<int> &row : res) {
        sort(row.begin(), row.end());
        for (int value : row)
            cout << value << " ";
        cout << "\n";
    }
}