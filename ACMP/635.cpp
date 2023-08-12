#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Team {
    int id, problems, penalty;

    bool operator < (const Team &that) const {
        if (problems != that.problems)
            return problems > that.problems;
        return penalty < that.penalty;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int teamACount, teamBCount;
    cin >> teamACount >> teamBCount;

    vector<Team> teamsA;
    for (int i = 0; i < teamACount; i++) {
        int id, problems, penalty;
        cin >> id >> problems >> penalty;

        if (problems)
            teamsA.push_back({ id, problems, penalty });
    }
    
    set<int> teamsB;
    for (int i = 0; i < teamBCount; i++) {
        int id, problems, penalty;
        cin >> id >> problems >> penalty;

        if (problems)
            teamsB.insert(id);
    }

    sort(teamsA.begin(), teamsA.end());

    if (!teamsA.empty()) {
        int threshold = min(teamsA[0].problems, teamsA[max<int>(teamsA.size() / 2 - 1, 0)].problems + 1);

        for (auto &[id, problems, penalty] : teamsA)
            if (problems >= threshold)
                teamsB.insert(id);
    }

    cout << teamsB.size() << "\n";
    for (int id : teamsB)
        cout << id << " ";
}