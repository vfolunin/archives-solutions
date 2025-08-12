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

    int size;
    cin >> size;

    map<int, set<int>> pos;
    for (int i = 0; i < size; i++) {
        int volume;
        cin >> volume;

        pos[volume].insert(i);
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int needVolume;
        cin >> needVolume;

        int volume = -1;
        for (auto it = pos.lower_bound(needVolume); it != pos.end(); it++) {
            if (volume == -1 || *pos[volume].begin() > *it->second.begin())
                volume = it->first;
        }
        if (volume == -1)
            continue;

        if (volume > needVolume)
            pos[volume - needVolume].insert(*pos[volume].begin());
        pos[volume].erase(pos[volume].begin());
        if (pos[volume].empty())
            pos.erase(volume);
    }

    int res = 0;
    for (auto &[volume, pos] : pos)
        res += volume * pos.size();

    cout << res;
}