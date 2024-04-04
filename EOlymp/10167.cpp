#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int teamCount;
    cin >> teamCount;

    unordered_map<int, int> teamOf;
    for (int teamId = 0; teamId < teamCount; teamId++) {
        int teamSize;
        cin >> teamSize;

        for (int i = 0; i < teamSize; i++) {
            int studentId;
            cin >> studentId;

            teamOf[studentId] = teamId;
        }
    }

    queue<int> outerQ;
    vector<queue<int>> innerQ(teamCount);

    for (string type; cin >> type; ) {
        if (type == "ENQUEUE") {
            int studentId;
            cin >> studentId;

            int teamId = teamOf[studentId];

            if (innerQ[teamId].empty())
                outerQ.push(teamId);

            innerQ[teamId].push(studentId);                
        } else {
            int teamId = outerQ.front();

            cout << innerQ[teamId].front() << "\n";

            innerQ[teamId].pop();

            if (innerQ[teamId].empty())
                outerQ.pop();
        }
    }
}