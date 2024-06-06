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

    int voteCount, candidateCount;
    cin >> voteCount >> candidateCount;

    vector<int> votes(candidateCount);
    for (int i = 0; i < voteCount; i++) {
        int candidate;
        cin >> candidate;
        votes[candidate - 1]++;
    }

    cout << (*max_element(votes.begin(), votes.end()) * 2 > voteCount ? "YES" : "NO");
}