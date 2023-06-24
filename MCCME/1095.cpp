#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> readTokens() {
    string s;
    getline(cin, s);

    vector<int> tokens;

    int value = 0;
    for (char c : s) {
        if (isdigit(c)) {
            value = value * 10 + c - '0';
        } else {
            tokens.push_back(value);
            value = 0;
            tokens.push_back(c == '+' ? -1 : -2);
        }
    }
    tokens.push_back(value);

    return tokens;
}

int rec(vector<int> &tokens, int l, int r, vector<vector<int>> &memo, vector<vector<int>> &lastOpIndex) {
    int &res = memo[l][r];
    if (res)
        return res;

    if (l == r)
        return res = tokens[l];

    for (int i = l + 1; i < r; i += 2) {
        int a = rec(tokens, l, i - 1, memo, lastOpIndex);
        int b = rec(tokens, i + 1, r, memo, lastOpIndex);
        int res = tokens[i] == -1 ? a + b : a * b;

        if (memo[l][r] < res) {
            memo[l][r] = res;
            lastOpIndex[l][r] = i;
        }
    }

    return res;
}

void print(vector<int> &tokens, int l, int r, vector<vector<int>> &lastOpIndex) {
    if (l == r) {
        cout << tokens[l];
        return;
    }

    cout << "(";
    print(tokens, l, lastOpIndex[l][r] - 1, lastOpIndex);
    cout << (tokens[lastOpIndex[l][r]] == -1 ? "+" : "*");
    print(tokens, lastOpIndex[l][r] + 1, r, lastOpIndex);
    cout << ")";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> tokens = readTokens();

    vector<vector<int>> memo(tokens.size(), vector<int>(tokens.size()));
    vector<vector<int>> lastOpIndex(tokens.size(), vector<int>(tokens.size()));
    rec(tokens, 0, tokens.size() - 1, memo, lastOpIndex);

    print(tokens, 0, tokens.size() - 1, lastOpIndex);
}