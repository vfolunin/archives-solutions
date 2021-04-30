#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int candidateCount;
    cin >> candidateCount;
    while (!isalpha(cin.peek()))
        cin.ignore();

    map<string, string> partyOf;
    for (int i = 0; i < candidateCount; i++) {
        string candidate, party;
        getline(cin, candidate);
        getline(cin, party);
        partyOf[candidate] = party;
    }

    int voteCount;
    cin >> voteCount;
    while (!isalpha(cin.peek()))
        cin.ignore();

    map<string, int> votes;
    for (auto &[candidate, _] : partyOf)
        votes[candidate];

    int maxVotes = 0;
    string maxCandidate;

    for (int i = 0; i < voteCount; i++) {
        string candidate;
        getline(cin, candidate);

        if (!partyOf.count(candidate))
            continue;

        votes[candidate]++;

        if (maxVotes < votes[candidate]) {
            maxVotes = votes[candidate];
            maxCandidate = candidate;
        }
    }

    if (test)
        cout << "\n";

    for (auto &[candidate, votes] : votes) {
        if (votes == maxVotes && candidate != maxCandidate) {
            cout << "tie\n";
            return;
        }
    }

    cout << partyOf[maxCandidate] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}