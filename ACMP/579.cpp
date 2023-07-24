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

    vector<int> sum(2);
    vector<vector<int>> indexes(2);

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value > 0) {
            sum[0] += value;
            indexes[0].push_back(i);
        } else {
            sum[1] -= value;
            indexes[1].push_back(i);
        }
    }

    vector<int> &resIndexes = indexes[sum[0] < sum[1]];

    cout << resIndexes.size() << "\n";
    for (int i : resIndexes)
        cout << i + 1 << " ";
}