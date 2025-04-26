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

    int candidateCount, voteCount;
    cin >> candidateCount >> voteCount;
    
    vector<int> count(candidateCount);
    for (int i = 0; i < voteCount; i++) {
        int candidate;
        cin >> candidate;

        count[candidate - 1]++;
    }

    cout.precision(2);
    for (int count : count)
        cout << fixed << count * 100.0 / voteCount << "%\n";
}