#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int partyCount;
    cin >> partyCount;

    vector<int> votes(partyCount);
    int totalVotes = 0;
    for (int &v : votes) {
        cin >> v;
        totalVotes += v;
    }

    vector<int> power(partyCount);
    for (int mask = 0; mask < (1 << partyCount); mask++) {
        int maskVotes = 0;
        for (int bit = 0; bit < partyCount; bit++)
            if (mask & (1 << bit))
                maskVotes += votes[bit];
        
        if (maskVotes * 2 > totalVotes)
            for (int bit = 0; bit < partyCount; bit++)
                if (mask & (1 << bit) && 2 * (maskVotes - votes[bit]) <= totalVotes)
                    power[bit]++;
    }

    for (int i = 0; i < partyCount; i++)
        cout << "party " << i + 1 << " has power index " << power[i] << "\n";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}