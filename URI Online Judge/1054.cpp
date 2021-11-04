#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int stoneCount, width;
    cin >> stoneCount >> width;

    vector<int> stones = { 0, 0 };
    for (int i = 0; i < stoneCount; i++) {
        char type, hyphen;
        int x;
        cin >> type >> hyphen >> x;
        stones.push_back(x);
        if (type == 'B')
            stones.push_back(x);
    }
    stones.push_back(width);
    stones.push_back(width);

    int res = 0;
    for (int i = 0; i + 2 < stones.size(); i += 2)
        res = max(res, stones[i + 2] - stones[i]);
    for (int i = 1; i + 2 < stones.size(); i += 2)
        res = max(res, stones[i + 2] - stones[i]);

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}