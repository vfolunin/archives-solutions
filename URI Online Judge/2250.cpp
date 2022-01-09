#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(pair<string, int> &a, pair<string, int> &b) {
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

bool solve(int test) {
    int playerCount;
    cin >> playerCount;

    if (!playerCount)
        return 0;

    vector<pair<string, int>> players(playerCount);
    for (auto &[name, score] : players) {
        cin >> name;

        vector<int> marks(12);
        for (int &mark : marks)
            cin >> mark;

        sort(marks.begin(), marks.end());
        for (int i = 1; i < marks.size() - 1; i++)
            score += marks[i];
    }

    sort(players.begin(), players.end(), compare);

    cout << "Teste " << test << "\n";
    for (int i = 0, place = 1; i < playerCount; i++) {
        if (i && players[i - 1].second > players[i].second)
            place = i + 1;
        cout << place << " " << players[i].second << " " << players[i].first << "\n";
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}