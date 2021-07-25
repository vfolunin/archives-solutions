#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int songCount, timeLimit;
    cin >> songCount >> timeLimit;

    vector<int> songs(songCount);
    for (int &song : songs)
        cin >> song;
    songs.push_back(678);

    vector<pair<int, int>> res(10000, { 0, 0 });
    for (int song : songs) {
        for (int startTime = 9999 - song; startTime >= 0; startTime--) {
            if (startTime >= timeLimit)
                continue;
            pair<int, int> candidate = { res[startTime].first + 1, res[startTime].second + song };
            res[startTime + song] = max(res[startTime + song], candidate);
        }
    }

    auto &[resSongs, resTime] = *max_element(res.begin(), res.end());

    cout << "Case " << test << ": " << resSongs << " " << resTime << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}