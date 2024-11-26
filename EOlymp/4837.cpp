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

    int count, size;
    cin >> count >> size;

    string mask = string(size - count, '0') + string(count, '1');
    vector<vector<int>> res;

    do {
        res.emplace_back();

        for (int i = 0; i < size; i++)
            if (mask[i] == '1')
                res.back().push_back(i + 1);

        sort(res.back().begin(), res.back().end());
    } while (next_permutation(mask.begin(), mask.end()));

    sort(res.begin(), res.end());

    for (vector<int> &row : res) {
        for (int value : row)
            cout << value << " ";
        cout << "\n";
    }
}