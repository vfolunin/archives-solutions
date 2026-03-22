#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(char op, int depth, map<char, string> &rule) {
    static map<pair<char, int>, int> memo;
    if (memo.count({ op, depth }))
        return memo[{ op, depth }];
    int &res = memo[{ op, depth }];

    if (!depth)
        return res = 0;

    res = 1;
    for (char nextOp : rule[op])
        res += rec(nextOp, depth - 1, rule);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<char, string> rule;
    for (char op : { 'N', 'S', 'W', 'E', 'U', 'D' })
        getline(cin, rule[op]);

    char op;
    int depth;
    cin >> op >> depth;

    cout << rec(op, depth, rule);
}