#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> prepare() {
    vector<vector<int>> res;
    for (int a = 1; a * a * a <= 1e9; a++) {
        for (int b = 1; b * b * b <= 1e9; b++) {
            int c = a * a * a + b * b * b;
            if (c % 10 == 3)
                res.push_back({ a, b, c / 10 });
        }
    }
    return res;
}

bool solve(int test) {
    int l, r;
    if (!(cin >> l >> r))
        return 0;

    static vector<vector<int>> triplets = prepare();

    int count = 0;
    for (auto &t : triplets)
        count += l <= t[0] && t[0] <= r && l <= t[1] && t[1] <= r && l <= t[2] && t[2] <= r;

    cout << "Case " << test << ": " << count << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}