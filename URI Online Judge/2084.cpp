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

    int candidateCount;
    cin >> candidateCount;

    vector<int> votes(candidateCount);
    int totalVotes = 0;
    for (int &v : votes) {
        cin >> v;
        totalVotes += v;
    }

    sort(votes.rbegin(), votes.rend());

    if (votes[0] * 100 >= totalVotes * 45 ||
        votes[0] * 100 >= totalVotes * 40 && (votes[0] - votes[1]) * 100 >= totalVotes * 10)
        cout << "1\n";
    else
        cout << "2\n";
}