#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int eval(string &s, int l, int r, string &varNames, vector<int> &vars) {
    int d = 0, p1 = -1, p2 = -1;
    for (int i = l; i <= r; i++) {
        if (s[i] == '(')
            d++;
        if (s[i] == ')')
            d--;
        if (!d) {
            if (s[i] == '+' || s[i] == '-')
                p1 = i;
            if (s[i] == '*')
                p2 = i;
        }
    }

    if (p1 != -1) {
        if (s[p1] == '+')
            return eval(s, l, p1 - 1, varNames, vars) + eval(s, p1 + 1, r, varNames, vars);
        else
            return eval(s, l, p1 - 1, varNames, vars) - eval(s, p1 + 1, r, varNames, vars);
    }

    if (p2 != -1)
        return eval(s, l, p2 - 1, varNames, vars) * eval(s, p2 + 1, r, varNames, vars);

    if (s[l] == '(' && s[r] == ')')
        return eval(s, l + 1, r - 1, varNames, vars);
    
    return vars[varNames.find(s[l])];
}

bool solve() {
    int varCount;
    cin >> varCount;

    vector<int> vars(varCount);
    for (int &var : vars)
        cin >> var;

    int value;
    string line;
    if (!(cin >> value >> line))
        return 0;

    string varNames;
    for (char c : line)
        if (isalpha(c))
            varNames += c;

    sort(varNames.begin(), varNames.end());
    varNames.erase(unique(varNames.begin(), varNames.end()), varNames.end());

    sort(vars.begin(), vars.end());
    do {
        if (eval(line, 0, line.size() - 1, varNames, vars) == value) {
            cout << "YES\n";
            return 1;
        }
    } while (next_permutation(vars.begin(), vars.end()));

    cout << "NO\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}