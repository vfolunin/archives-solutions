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

    int size, targetSum;
    cin >> size >> targetSum;

    unordered_map<long long, int> pos;
    long long prefixSum = 0;
    pos[prefixSum] = 0;

    int resL = -1, resR;
    for (int r = 1; r <= size; r++) {
        int value;
        cin >> value;

        prefixSum += value;

        if (pos.count(prefixSum - targetSum)) {
            int l = pos[prefixSum - targetSum] + 1;
            if (resL == -1 || resR - resL >= r - l) {
                resL = l;
                resR = r;
            }
        }

        pos[prefixSum] = r;
    }

    if (resL == -1)
        cout << -1;
    else
        cout << resL << " " << resR;
}