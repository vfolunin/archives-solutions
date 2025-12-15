#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getDiff(int n) {
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0)
            return n / d - d;
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int limit, d;
    cin >> limit >> d;

    vector<pair<int, int>> res;
    for (int i = 1; i <= limit; i++) {
        int diff = getDiff(i);
        if (diff && diff % d == 0)
            res.push_back({ i, diff });
    }

    for (int i = res.size() - 5; i < res.size(); i++)
        cout << res[i].first << " " << res[i].second << "\n";
}