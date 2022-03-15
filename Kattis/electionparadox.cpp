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

    int regionCount;
    cin >> regionCount;

    vector<int> regionVotes(regionCount);
    int totalVotes = 0;
    for (int &votes : regionVotes) {
        cin >> votes;
        totalVotes += votes;
    }

    sort(regionVotes.begin(), regionVotes.end());

    for (int i = 0; i <= regionCount / 2; i++)
        totalVotes -= regionVotes[i] / 2 + 1;

    cout << totalVotes;
}