#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(int less, int greater, int up) {
    static vector<vector<vector<long long>>> memo(30, vector<vector<long long>>(30, vector<long long>(2, -1)));
    long long &res = memo[less][greater][up];
    if (res != -1)
        return res;

    if (!less && !greater)
        return res = 1;

    res = 0;
    if (up)
        for (int i = 0; i < greater; i++)
            res += rec(less + i, greater - i - 1, 0);
    else
        for (int i = 0; i < less; i++)
            res += rec(less - i - 1, greater + i, 1);
    return res;
}

bool solve() {
    int count, start;
    if (!(cin >> count >> start))
        return 0;

    long long res;
    if (count <= 2)
        res = 1;
    else if (start == 1)
        res = rec(1, count - 3, 0);
    else
        res = rec(start - 1, count - start, 0);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}