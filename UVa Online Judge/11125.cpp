#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(vector<int> &k, int first, int firstSize, int last, int lastSize) {
    static vector<vector<vector<vector<vector<vector<vector<vector<long long>>>>>>>> memo(
        8, vector<vector<vector<vector<vector<vector<vector<long long>>>>>>>(
        8, vector<vector<vector<vector<vector<vector<long long>>>>>>(
        8, vector<vector<vector<vector<vector<long long>>>>>(
        8, vector<vector<vector<vector<long long>>>>(
        4, vector<vector<vector<long long>>>(4, vector<vector<long long>>(4, vector<long long>(4, -1)))))))
    );
    long long &res = memo[k[0]][k[1]][k[2]][k[3]][first][firstSize][last][lastSize];
    if (res != -1)
        return res;

    if (count(k.begin(), k.end(), 0) == 3) {
        int m = max_element(k.begin(), k.end()) - k.begin();
        if (first == m && last == m && k[m] == firstSize && k[m] == lastSize)
            return res = 1;
    }

    k[last] -= lastSize;
    res = 0;

    for (int prev = 0; prev < 4; prev++) {
        if (prev == last)
            continue;
        for (int prevSize = 1; prevSize <= 3 && prevSize <= k[prev]; prevSize++) {
            if (prevSize == lastSize)
                continue;
            res += rec(k, first, firstSize, prev, prevSize);
        }
    }

    k[last] += lastSize;

    return res;
}

void solve() {
    int colorCount;
    cin >> colorCount;

    vector<int> k(4);
    for (int i = 0; i < colorCount; i++)
        cin >> k[i];

    if (!*max_element(k.begin(), k.end())) {
        cout << "1\n";
        return;
    }

    long long res = 0;
    for (int first = 0; first < 4; first++)
        for (int firstSize = 1; firstSize <= 3 && firstSize <= k[first]; firstSize++)
            for (int last = 0; last < 4; last++)
                for (int lastSize = 1; lastSize <= 3 && lastSize <= k[last]; lastSize++)
                    if (first != last && firstSize != lastSize)
                        res += rec(k, first, firstSize, last, lastSize);

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}