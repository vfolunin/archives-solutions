#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string rec(vector<string> &tokens) {
    string op = tokens.back();
    tokens.pop_back();

    if (isdigit(op[0]))
        return op;

    string r = rec(tokens);
    string l = rec(tokens);
    return "(" + l + op + r + ")";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> tokens;
    for (string token; cin >> token; )
        tokens.push_back(token);

    cout << rec(tokens);
}