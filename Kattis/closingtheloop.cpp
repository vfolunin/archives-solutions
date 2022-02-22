#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int segmentCount;
    cin >> segmentCount;

    vector<vector<int>> segments(2);
    for (int i = 0; i < segmentCount; i++) {
        int segment;
        char color;
        cin >> segment >> color;
        segments[color == 'R'].push_back(segment);
    }

    sort(segments[0].rbegin(), segments[0].rend());
    sort(segments[1].rbegin(), segments[1].rend());

    int res = 0;
    for (int i = 0; i < segments[0].size() && i < segments[1].size(); i++)
        res += segments[0][i] + segments[1][i] - 2;

    cout << "Case #" << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}