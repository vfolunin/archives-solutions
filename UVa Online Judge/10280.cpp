#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int targetVolume, bottleCount;
    cin >> targetVolume >> bottleCount;

    targetVolume *= 1000;

    vector<pair<int, int>> bottles(bottleCount);
    for (auto &[l, r] : bottles)
        cin >> l >> r;

    sort(bottles.begin(), bottles.end());

    vector<pair<int, int>> merged;
    for (auto &[l, r] : bottles) {
        if (merged.empty() || merged.back().second + 1 < l)
            merged.push_back({ l, r });
        else
            merged.back().second = max(merged.back().second, r);
    }

    int threshold = 2e9;
    for (auto &[l, r] : merged)
        threshold = min(threshold, l * (r - 2) / (r - l));

    if (test)
        cout << "\n";

    if (targetVolume >= threshold) {
        cout << "0\n";
        return;
    }

    vector<int> res(targetVolume + 1);
    for (int i = 0; i < res.size(); i++)
        res[i] = i;

    for (auto &[l, r] : merged) {
        deque<int> q;

        for (int volume = 0; volume <= targetVolume; volume++) {
            int pos = volume - l;
            if (pos >= 0) {
                while (!q.empty() && res[q.back()] >= res[pos])
                    q.pop_back();
                q.push_back(pos);
            }

            while (!q.empty() && q.front() < volume - r)
                q.pop_front();

            if (!q.empty())
                res[volume] = min(res[volume], res[q.front()]);
        }
    }

    cout << res[targetVolume] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve(test);
}