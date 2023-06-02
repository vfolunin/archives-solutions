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

    int size, maxValue;
    cin >> size >> maxValue;

    if (size == 1) {
        cout << maxValue;
        return 0;
    }

    vector<vector<long long>> cur(2, vector<long long>(maxValue + 1));
    for (int last = 1; last <= maxValue; last++) {
        cur[0][last] = maxValue - last;
        cur[1][last] = last - 1;
    }

    for (int i = 3; i <= size; i++) {
        vector<vector<long long>> prev = cur;
        cur.assign(2, vector<long long>(maxValue + 1));

        for (int last = 1; last <= maxValue; last++) {
            for (int prevLast = 1; prevLast <= maxValue; prevLast++) {
                if (prevLast > last)
                    cur[0][last] += prev[1][prevLast];
                if (prevLast < last)
                    cur[1][last] += prev[0][prevLast];
            }
        }
    }

    long long res = 0;
    for (int last = 1; last <= maxValue; last++) {
        res += cur[0][last];
        res += cur[1][last];
    }

    cout << res;
}