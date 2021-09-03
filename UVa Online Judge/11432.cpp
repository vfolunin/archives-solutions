#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(int k0, int k1, int last, int row, int maxRow,
              vector<vector<vector<vector<long long>>>> &memo) {
    long long &res = memo[k0][k1][last][row];
    if (res != -1)
        return res;

    if (k0 + k1 <= 1)
        return res = k0 >= k1;

    res = 0;
    if (!last) {
        if (row == 1) {
            for (int prevRow = 1; prevRow <= maxRow && prevRow <= k1; prevRow++)
                res += rec(k0 - 1, k1, 1, prevRow, maxRow, memo);
            return res;
        }        
        return res = rec(k0 - 1, k1, 0, row - 1, maxRow, memo);
    } else {
        if (row == 1) {
            for (int prevRow = 1; prevRow <= maxRow && prevRow <= k0; prevRow++)
                res += rec(k0, k1 - 1, 0, prevRow, maxRow, memo);
            return res;
        }
        return res = rec(k0, k1 - 1, 1, row - 1, maxRow, memo);
    }
}

bool solve(int test) {
    int maxLen, maxRow;
    cin >> maxLen >> maxRow;

    if (maxLen == -1)
        return 0;

    vector<vector<vector<vector<long long>>>> memo(34,
        vector<vector<vector<long long>>>(34,
            vector<vector<long long>>(2, vector<long long>(34, -1))
        )
    );

    long long res = 0;
    for (int row = 1; row <= maxLen; row++)
        res += rec(maxLen, maxLen, 1, row, maxRow, memo);
    
    cout << "Case " << test << ": " << 2 * res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}