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

    vector<int> colSum(3);
    for (int &sum : colSum)
        cin >> sum;

    vector<int> rowSum(3);
    for (int &sum : rowSum)
        cin >> sum;

    int res = 0;
    for (int mask = 0; mask < (1 << 9); mask++) {
        vector<int> curColSum(3), curRowSum(3);
        for (int bit = 0; bit < 9; bit++) {
            if (mask & (1 << bit)) {
                curColSum[bit % 3]++;
                curRowSum[bit / 3]++;
            }
        }
        res += curColSum == colSum && curRowSum == rowSum;
    }

    cout << res;
}