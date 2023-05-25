#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int handshakeCount(int teamSize) {
    return teamSize * (teamSize - 1) / 2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int peopleCount, teamCount;
    cin >> peopleCount >> teamCount;

    int smallTeamSize = peopleCount / teamCount;
    int largeTeamSize = smallTeamSize + 1;
    int largeTeamCount = peopleCount % teamCount;
    int smallTeamCount = teamCount - largeTeamCount;
    int minHandshakeCount = smallTeamCount * handshakeCount(smallTeamSize) + largeTeamCount * handshakeCount(largeTeamSize);

    int maxHandshakeCount = handshakeCount(peopleCount - teamCount + 1);

    cout << minHandshakeCount << "\n" << maxHandshakeCount;
}