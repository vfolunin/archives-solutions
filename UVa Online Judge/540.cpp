#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

struct TeamQueue {
    deque<pair<int, deque<int>>> teams;
    unordered_map<int, pair<int, deque<int>> *> teamPos;

    void push(int id, int team) {
        if (teamPos.count(team)) {
            teamPos[team]->second.push_back(id);
        } else {
            teams.push_back({ team, {id} });
            teamPos[team] = &teams[teams.size() - 1];
        }
    }

    int pop() {
        int res = teams.front().second.front();
        teams.front().second.pop_front();
        if (teams.front().second.empty()) {
            teamPos.erase(teams.front().first);
            teams.pop_front();
        }
        return res;
    }
};

bool solve(int test) {
    int teamCount;
    cin >> teamCount;

    if (!teamCount)
        return 0;

    unordered_map<int, int> teamOf;
    for (int i = 0; i < teamCount; i++) {
        int teammateCount;
        cin >> teammateCount;
        for (int j = 0; j < teammateCount; j++) {
            int id;
            cin >> id;
            teamOf[id] = i;
        }
    }

    TeamQueue queue;

    cout << "Scenario #" << test << "\n";
    while (1) {
        string op;
        cin >> op;

        if (op == "ENQUEUE") {
            int id;
            cin >> id;
            queue.push(id, teamOf[id]);
        } else if (op == "DEQUEUE") {
            cout << queue.pop() << "\n";
        } else {
            break;
        }
    }
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}