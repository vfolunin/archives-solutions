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

    string party;
    vector<string> parties;

    while (1) {
        getline(cin, party);

        if (party == "VOTES:")
            break;

        if (party != "PARTIES:")
            parties.push_back(party);
    }

    map<string, int> voteCount;
    int totalVoteCount = 0;

    while (getline(cin, party)) {
        voteCount[party]++;
        totalVoteCount++;
    }

    for (string &party : parties)
        if (voteCount[party] * 100 >= totalVoteCount * 7)
            cout << party << "\n";
}