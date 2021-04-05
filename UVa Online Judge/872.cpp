#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string readLetters() {
    string line;
    if (!getline(cin, line))
        return "";
    line.erase(remove(line.begin(), line.end(), ' '), line.end());
    return line;
}

bool rec(string &letters, string &rules, string &order) {
    if (order.size() == letters.size()) {
        for (int i = 0; i < order.size(); i++)
            cout << order[i] << (i + 1 < order.size() ? " " : "\n");
        return 1;
    }

    bool res = 0;

    for (int li = 0; li < letters.size(); li++) {
        if (letters[li] == '#')
            continue;

        bool ok = 1;
        for (int ri = 2; ok && ri < rules.size(); ri += 3)
            ok &= rules[ri] != letters[li] || order.find(rules[ri - 2]) != -1;
        if (!ok)
            continue;

        order.push_back(letters[li]);
        letters[li] = '#';
        res |= rec(letters, rules, order);
        letters[li] = order.back();
        order.pop_back();
    }

    return res;
}

void solve(int test) {
    cin.ignore();
    string letters = readLetters();
    sort(letters.begin(), letters.end());
    string rules = readLetters();

    if (test)
        cout << "\n";
    string order;
    if (!rec(letters, rules, order))
        cout << "NO\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve(i);
}