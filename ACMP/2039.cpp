#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int size, int bulls, int cows, int i, int curBulls, int curCows, vector<int> &used) {
    if (i == size)
        if (curBulls == bulls && curCows >= cows)
            return 1;
        else
            return 0;

    int res = 0;
    for (int d = 0; d < used.size(); d++) {
        if (used[d])
            continue;

        used[d] = 1;
        res += rec(size, bulls, cows, i + 1, curBulls + (d == i), curCows + (d != i && d < size), used);
        used[d] = 0;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, bulls, cows;
    cin >> size >> bulls >> cows;

    vector<int> used(10);
    cout << rec(size, bulls, cows, 0, 0, 0, used);
}