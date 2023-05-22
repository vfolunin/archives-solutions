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
    while (getline(cin, party))
        voteCount[party]++;

    sort(parties.begin(), parties.end(), [&](string &a, string &b) {
        if (voteCount[a] != voteCount[b])
            return voteCount[a] > voteCount[b];
        return a < b;
    });

    for (string &party : parties)
        cout << party << "\n";
}