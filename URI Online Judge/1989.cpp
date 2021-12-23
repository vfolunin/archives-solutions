#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int seasonCount, episodeTime;
    cin >> seasonCount >> episodeTime;

    if (seasonCount < 0)
        return 0;

    long long totalTime = 0, totalEpisodeCount = 0;
    for (int i = 0; i < seasonCount; i++) {
        int episodeCount;
        cin >> episodeCount;
        totalEpisodeCount += episodeCount;
        totalTime += totalEpisodeCount * episodeTime;
    }

    cout << totalTime << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    while (solve());
}