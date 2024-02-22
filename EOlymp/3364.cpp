#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int ruleCount;
    cin >> ruleCount;
    cin.ignore();

    vector<string> rules(ruleCount);
    for (string &rule : rules)
        getline(cin, rule);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int index;
        cin >> index;

        cout << "Rule " << index << ": ";
        if (1 <= index && index <= rules.size())
            cout << rules[index - 1] << "\n";
        else
            cout << "No such rule\n";
    }
}