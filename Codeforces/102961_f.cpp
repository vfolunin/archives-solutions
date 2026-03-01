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

    int movieCount;
    cin >> movieCount;

    vector<pair<int, int>> movies(movieCount);
    for (auto &[l, r] : movies)
        cin >> l >> r;
    sort(movies.begin(), movies.end(), [](auto &a, auto &b) { return a.second < b.second; });

    int res = 0, last = 0;
    for (auto &[l, r] : movies) {
        if (l >= last) {
            res++;
            last = r;
        }
    }

    cout << res;
}