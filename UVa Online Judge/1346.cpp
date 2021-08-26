#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Song {
    int id;
    double len, freq;

    bool operator < (const Song &that) const {
        return len * that.freq < that.len * freq;
    }
};

bool solve() {
    int songCount;
    if (!(cin >> songCount))
        return 0;

    vector<Song> songs(songCount);
    for (auto &[id, len, freq] : songs)
        cin >> id >> len >> freq;

    sort(songs.begin(), songs.end());

    int i;
    cin >> i;

    cout << songs[i - 1].id << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}