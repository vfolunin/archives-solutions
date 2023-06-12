#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool check(string &order, string &rule) {
    int lhs = order.find(rule[0]);
    int rhs = order.find(rule[2]);
    if (rule[1] == '<')
        return lhs < rhs;
    if (rule[1] == '>')
        return lhs > rhs;
    return 1;
}

bool check(string &order, vector<string> &rules) {
    for (string &rule : rules)
        if (!check(order, rule))
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> rules(3);
    for (string &rule : rules)
        cin >> rule;

    string order = "abc";
    while (!check(order, rules))
        next_permutation(order.begin(), order.end());

    cout << order;
}