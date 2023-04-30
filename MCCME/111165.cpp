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

    int userCount;
    cin >> userCount;

    vector<int> voteCount(userCount);
    int maxVoteCount = 0;

    for (int vote; cin >> vote; )
        if (vote <= userCount)
            maxVoteCount = max(maxVoteCount, ++voteCount[vote - 1]);

    for (int user = 0; user < userCount; user++)
        if (voteCount[user] == maxVoteCount)
            cout << user + 1 << " ";
}