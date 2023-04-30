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

    int userCount, voteCount;
    cin >> userCount >> voteCount;

    vector<int> votes(userCount);
    int maxVotes = 0;

    for (int i = 0; i < voteCount; i++) {
        int vote;
        cin >> vote;
        if (vote <= userCount)
            maxVotes = max(maxVotes, ++votes[vote - 1]);
    }

    for (int user = 0; user < userCount; user++)
        if (votes[user] == maxVotes)
            cout << user + 1 << " ";
}