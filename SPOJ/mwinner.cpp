#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string teamA, teamB;
    int scoreA, scoreB;
    cin >> teamA >> scoreA >> teamB >> scoreB;

    if (scoreA > scoreB)
        cout << teamA << " won by " << scoreA - scoreB << " runs\n";
    else if (scoreA < scoreB)
        cout << teamB << " won by " << scoreB - scoreA << " runs\n";
    else
        cout << "MATCH DRAW\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}