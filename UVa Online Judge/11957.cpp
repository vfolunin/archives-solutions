#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e6 + 7;

void solve(int test) {
    int size;
    cin >> size;

    vector<string> a(size);
    int si, sj;
    for (int i = 0; i < size; i++) {
        cin >> a[i];
        if (int j = a[i].find('W'); j != -1) {
            si = i;
            sj = j;
        }
    }

    vector<vector<long long>> res(size, vector<long long>(size));
    res[si][sj] = 1;

    for (int i = size - 1; i > 0; i--) {
        for (int j = 0; j < size; j++) {
            if (!res[i][j])
                continue;

            if (j - 1 >= 0) {
                if (a[i - 1][j - 1] != 'B')
                    res[i - 1][j - 1] = (res[i - 1][j - 1] + res[i][j]) % MOD;
                else if (i - 2 >= 0 && j - 2 >= 0 && a[i - 2][j - 2] != 'B')
                    res[i - 2][j - 2] = (res[i - 2][j - 2] + res[i][j]) % MOD;
            }
            if (j + 1 < size) {
                if (a[i - 1][j + 1] != 'B')
                    res[i - 1][j + 1] = (res[i - 1][j + 1] + res[i][j]) % MOD;
                else if (i - 2 >= 0 && j + 2 < size && a[i - 2][j + 2] != 'B')
                    res[i - 2][j + 2] = (res[i - 2][j + 2] + res[i][j]) % MOD;
            }
        }
    }

    long long resSum = 0;
    for (int j = 0; j < size; j++)
        resSum = (resSum + res[0][j]) % MOD;

    cout << "Case " << test << ": " << resSum << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}