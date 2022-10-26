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

    vector<vector<int>> cost(size, vector<int>(3));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < 3; j++)
            cin >> cost[i][j];
    
    vector<int> res(size + 1);
    for (int i = 1; i <= size; i++) {
        res[i] = res[i - 1] + cost[i - 1][0];
        if (i >= 2 && res[i] > res[i - 2] + cost[i - 2][1])
            res[i] = res[i - 2] + cost[i - 2][1];
        if (i >= 3 && res[i] > res[i - 3] + cost[i - 3][2])
            res[i] = res[i - 3] + cost[i - 3][2];
    }
    cout << res.back();
}