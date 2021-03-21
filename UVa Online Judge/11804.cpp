#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Player {
    string name;
    int attack, defence;
};

void solve(int test) {
    vector<Player> players(10);
    for (auto &[name, attack, defence] : players)
        cin >> name >> attack >> defence;

    vector<int> mask(10);
    fill(mask.begin() + 5, mask.end(), 1);

    int resAttack = 0, resDefence = 0;
    set<string> resAttackers, resDefenders;

    do {
        int curAttack = 0, curDefence = 0;
        set<string> curAttackers, curDefenders;

        for (int bit = 0; bit < 10; bit++) {
            if (mask[bit]) {
                curAttack += players[bit].attack;
                curAttackers.insert(players[bit].name);
            } else {
                curDefence += players[bit].defence;
                curDefenders.insert(players[bit].name);
            }
        }

        if (curAttack > resAttack || curAttack == resAttack && curDefence > resDefence ||
            curAttack == resAttack && curDefence == resDefence && curAttackers < resAttackers) {
            resAttack = curAttack;
            resDefence = curDefence;
            resAttackers = curAttackers;
            resDefenders = curDefenders;
        }
    } while (next_permutation(mask.begin(), mask.end()));

    cout << "Case " << test << ":\n";
    cout << "(";
    for (auto it = resAttackers.begin(); it != resAttackers.end(); it++)
        cout << *it << (next(it) != resAttackers.end() ? ", " : ")\n");
    cout << "(";
    for (auto it = resDefenders.begin(); it != resDefenders.end(); it++)
        cout << *it << (next(it) != resDefenders.end() ? ", " : ")\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    for (int test = 1; test <= n; test++)
        solve(test);
}