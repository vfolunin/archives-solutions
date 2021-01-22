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

void rec(string &letters, string &rules, string &order) {
    if (order.size() == letters.size()) {
        cout << order << "\n";
        return;
    }
    for (int li = 0; li < letters.size(); li++) {
        if (letters[li] == '#')
            continue;

        bool ok = 1;
        for (int ri = 1; ok && ri < rules.size(); ri += 2)
            ok &= rules[ri] != letters[li] || order.find(rules[ri - 1]) != -1;
        if (!ok)
            continue;

        order.push_back(letters[li]);
        letters[li] = '#';
        rec(letters, rules, order);
        letters[li] = order.back();
        order.pop_back();
    }
}

bool solve(int test) {
    string letters = readLetters();
    if (letters.empty())
        return 0;
    sort(letters.begin(), letters.end());
    string rules = readLetters();

    if (test)
        cout << "\n";
    string order;
    rec(letters, rules, order);
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}