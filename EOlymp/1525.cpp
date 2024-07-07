#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size, mod;
    cin >> size >> mod;

    if (!size && !mod)
        return 0;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<vector<long long>> res(size + 1, vector<long long>(size + 1));
    for (int group = 0; group <= size; group++) {
        res[group][0] = 1 % mod;
        for (int take = 1; take <= group; take++)
            res[group][take] = (res[group - 1][take] + res[group - 1][take - 1] * a[group - 1]) % mod;
    }

    cout << *max_element(res[size].begin(), res[size].end()) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}