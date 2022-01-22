#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string line;
    cin >> line;

    if (line == "0")
        return 0;

    vector<string> args, ops;
    int n = 0;
    for (char c : line) {
        if (islower(c))
            args.push_back(string(1, c));
        else if (c == 'N')
            n++;
        else
            ops.push_back(string(1, c));
    }

    if (args.size() >= 1) {
        string arg = args.back();
        args.pop_back();
        args.push_back(string(n, 'N') + arg);
    }

    while (args.size() >= 2 && ops.size() >= 1) {
        string op = ops.back();
        ops.pop_back();
        string arg = args.back();
        args.pop_back();
        args.back() = op + arg + args.back();
    }

    if (!args.empty())
        cout << args.back() << "\n";
    else
        cout << "no WFF possible\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}