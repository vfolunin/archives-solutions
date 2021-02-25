#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int participantCount, competitorCount;
    cin >> participantCount >> competitorCount;

    int roundCount = 0;
    while (participantCount >= competitorCount) {
        participantCount -= competitorCount - 1;
        roundCount++;
    }

    if (participantCount == 1)
        cout << roundCount << "\n";
    else
        cout << "cannot do this\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}