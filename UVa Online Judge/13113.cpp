#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int candidateCount, stateCount;
    cin >> candidateCount >> stateCount;

    vector<long long> votes(candidateCount);
    long long voteSum = 0;

    for (int i = 0; i < stateCount; i++) {
        vector<double> percentage(candidateCount);
        for (double &p : percentage)
            cin >> p;

        long long totalVotes;
        cin >> totalVotes;

        for (int j = 0; j < candidateCount; j++)
            votes[j] += roundl(percentage[j] / 100 * totalVotes);
        voteSum += totalVotes;
    }

    if (test)
        cout << "\n";

    int m = max_element(votes.begin(), votes.end()) - votes.begin();
    if (votes[m] * 1000 >= voteSum * 501) {
        cout << m + 1 << " " << votes[m] << "\n";
        return;
    }

    votes[m] *= -1;
    int m2 = max_element(votes.begin(), votes.end()) - votes.begin();
    cout << m + 1 << " " << -votes[m] << "\n";
    cout << m2 + 1 << " " << votes[m2] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}