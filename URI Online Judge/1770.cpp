#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int songCount, playlistSize;
    if (!(cin >> songCount >> playlistSize))
        return 0;

    vector<int> songDuration(songCount);
    for (int &sd : songDuration)
        cin >> sd;

    set<int> listened;
    int listeningDuration = 0;

    for (int i = 0; i < playlistSize; i++) {
        int song;
        cin >> song;

        if (listened.size() < songCount)
            listeningDuration += songDuration[song - 1];
        listened.insert(song);
    }

    cout << (listened.size() == songCount ? listeningDuration : -1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}