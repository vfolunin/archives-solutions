#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int playerCount;
    if (!(cin >> playerCount))
        return 0;

    vector<vector<int>> exprs(playerCount, vector<int>(3));
    for (vector<int> &expr : exprs) {
        char eq;
        cin >> expr[0] >> expr[1] >> eq >> expr[2];
    }

    vector<string> losers;
    for (int i = 0; i < playerCount; i++) {
        string name, op;
        int ei;
        cin >> name >> ei >> op;
        ei--;

        if (op == "+" && exprs[ei][0] + exprs[ei][1] != exprs[ei][2] ||
            op == "-" && exprs[ei][0] - exprs[ei][1] != exprs[ei][2] ||
            op == "*" && exprs[ei][0] * exprs[ei][1] != exprs[ei][2] ||
            op == "I" && (exprs[ei][0] + exprs[ei][1] == exprs[ei][2] ||
                          exprs[ei][0] - exprs[ei][1] == exprs[ei][2] ||
                          exprs[ei][0] * exprs[ei][1] == exprs[ei][2]))
            losers.push_back(name);
    }

    if (losers.size() == 0) {
        cout << "You Shall All Pass!\n";
    } else if (losers.size() == playerCount) {
        cout << "None Shall Pass!\n";
    } else {
        sort(losers.begin(), losers.end());
        for (int i = 0; i < losers.size(); i++)
            cout << losers[i] << (i + 1 < losers.size() ? " " : "\n");
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}