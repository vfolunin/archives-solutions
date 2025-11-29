#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int playerCount;
    cin >> playerCount;

    vector<pair<string, vector<vector<int>>>> players(playerCount);
    for (auto &[name, card] : players) {
        cin >> name;

        card.assign(5, vector<int>(5));
        for (int y = 0; y < card.size(); y++)
            for (int x = 0; x < card.size(); x++)
                cin >> card[y][x];
    }

    int ballCount;
    cin >> ballCount;

    unordered_set<int> balls;
    for (int i = 0; i < ballCount; i++) {
        int ball;
        cin >> ball;

        balls.insert(ball);
    }

    vector<string> res;
    for (auto &[name, card] : players) {
        bool ok = 0;

        for (int y = 0; !ok && y < card.size(); y++) {
            bool curOk = 1;
            for (int x = 0; curOk && x < card.size(); x++)
                curOk &= balls.count(card[y][x]);
            ok |= curOk;
        }
        for (int x = 0; !ok && x < card.size(); x++) {
            bool curOk = 1;
            for (int y = 0; curOk && y < card.size(); y++)
                curOk &= balls.count(card[y][x]);
            ok |= curOk;
        }
        if (!ok) {
            bool curOk = 1;
            for (int i = 0; curOk && i < card.size(); i++)
                curOk &= balls.count(card[i][i]);
            ok |= curOk;
        }
        if (!ok) {
            bool curOk = 1;
            for (int i = 0; curOk && i < card.size(); i++)
                curOk &= balls.count(card[i][card.size() - 1 - i]);
            ok |= curOk;
        }

        if (ok)
            res.push_back(name);
    }

    cout << res.size() << "\n";
    for (string &name : res)
        cout << name << "\n";
}