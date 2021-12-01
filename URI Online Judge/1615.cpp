#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int candidateCount, voteCount;
    cin >> candidateCount >> voteCount;

    vector<int> votes(candidateCount);
    for (int i = 0; i < voteCount; i++) {
        int candidate;
        cin >> candidate;
        votes[candidate - 1]++;
    }

    int m = max_element(votes.begin(), votes.end()) - votes.begin();

    if (votes[m] * 2 > voteCount)
        cout << m + 1 << "\n";
    else
        cout << "-1\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}