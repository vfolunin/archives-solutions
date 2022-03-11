#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int candidateCount;
    cin >> candidateCount;

    vector<pair<int, int>> candidates(candidateCount);
    int totalVotes = 0;

    for (int i = 0; i < candidateCount; i++) {
        cin >> candidates[i].first;
        totalVotes += candidates[i].first;
        candidates[i].second = i;
    }

    sort(candidates.begin(), candidates.end());

    if (candidates.back().first * 2 > totalVotes)
        cout << "majority winner " << candidates.back().second + 1 << "\n";
    else if (candidates[candidateCount - 2].first < candidates.back().first)
        cout << "minority winner " << candidates.back().second + 1 << "\n";
    else
        cout << "no winner\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}