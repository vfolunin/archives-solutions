#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> read() {
    string line;
    getline(cin, line);

    vector<string> tokens;
    string token;
    for (char c : line) {
        if (c != ' ') {
            token += c;
        } else if (!token.empty()) {
            tokens.push_back(token);
            token = "";
        }
    }
    if (!token.empty())
        tokens.push_back(token);

    return tokens;
}

bool solve() {
    vector<string> tokens = read();
    if (tokens[0] == "*")
        return 0;

    for (int i = 1; i < tokens.size(); i++) {
        if (tolower(tokens[0][0]) != tolower(tokens[i][0])) {
            cout << "N\n";
            return 1;
        }
    }

    cout << "Y\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}