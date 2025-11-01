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

    vector<vector<int>> maxSum(size + 1, vector<int>(3));
    for (int size = 1; size < maxSum.size(); size++) {
        vector<int> a(3);
        for (int &value : a)
            cin >> value;

        for (int i = 0; i < a.size(); i++)
            for (int j = 0; j < a.size(); j++)
                if (i != j)
                    maxSum[size][i] = max(maxSum[size][i], maxSum[size - 1][j] + a[i]);
    }

    cout << *max_element(maxSum.back().begin(), maxSum.back().end());
}