#include <iostream>
#include <algorithm>
#include <vector>
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

    int threshold = 2e9;
    for (auto &[l, r] : bottles)
        threshold = min(threshold, l * l / (r - l));

    if (test)
        cout << "\n";

    if (targetVolume >= threshold) {
        cout << "0\n";
        return;
    }

    vector<int> res(targetVolume + 1);
    for (int i = 0; i < res.size(); i++)
        res[i] = i;        

    for (auto &[l, r] : bottles)
        for (int bottleVolume = l; bottleVolume <= r; bottleVolume++)
            for (int volume = bottleVolume; volume <= targetVolume; volume++)
                res[volume] = min(res[volume], res[volume - bottleVolume]);
        
    cout << res[targetVolume] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}