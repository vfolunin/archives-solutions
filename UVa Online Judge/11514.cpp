#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Power {
    string name;
    int attack, cost;
};

struct Villain {
    int defence;
    set<string> powers;

    bool isVulnerableTo(Power &p) {
        return defence <= p.attack && powers.count(p.name);
    }
};

set<string> split(string &line) {
    set<string> words;
    string word;
    for (char c : line) {
        if (c != ',') {
            word += c;
        } else {
            words.insert(word);
            word.clear();
        }
    }
    words.insert(word);
    return words;
}

bool solve() {
    int powerCount, villainCount, costLimit;
    cin >> powerCount >> villainCount >> costLimit;

    if (!powerCount && !villainCount && !costLimit)
        return 0;

    vector<Power> powers(powerCount);
    for (auto &[name, attack, cost] : powers)
        cin >> name >> attack >> cost;

    vector<Villain> villains(villainCount);
    for (auto &[defence, powers] : villains) {
        string line;
        cin >> line >> defence >> line;
        powers = split(line);
    }

    vector<vector<int>> cost(powerCount + 1, vector<int>(villainCount + 1, 1e9));
    cost[0][0] = 0;
    for (int pi = 1; pi <= powerCount; pi++) {
        cost[pi][0] = 0;
        for (int vi = 1; vi <= villainCount; vi++) {
            cost[pi][vi] = cost[pi - 1][vi];
            if (villains[vi - 1].isVulnerableTo(powers[pi - 1]))
                cost[pi][vi] = min(cost[pi][vi], cost[pi - 1][vi - 1] + powers[pi - 1].cost);
        }
    }

    for (int pi = 0; pi <= powerCount; pi++) {
        if (cost[pi][villainCount] <= costLimit) {
            cout << "Yes\n";
            return 1;
        }
    }

    cout << "No\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}