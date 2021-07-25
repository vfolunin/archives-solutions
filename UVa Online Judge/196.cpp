#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> split(string &s) {
    vector<string> words;
    string word;
    for (char c : s) {
        if (c != '+') {
            word += c;
        } else {
            words.push_back(word);
            word.clear();
        }
    }
    words.push_back(word);
    return words;
}

pair<int, int> getCell(string &s) {
    int row = 0, col = 0;
    for (char c : s) {
        if (isdigit(c))
            row = row * 10 + c - '0';
        else
            col = col * 26 + c - 'A' + 1;
    }
    return { row - 1, col - 1 };
}

vector<pair<int, int>> getFormula(string &s) {
    s = s.substr(1);
    vector<pair<int, int>> formula;
    for (string &part : split(s))
        formula.push_back(getCell(part));
    return formula;
}

int eval(vector<vector<int>> &val, vector<vector<vector<pair<int, int>>>> &formula, int y, int x) {
    if (!formula[y][x].empty()) {
        for (auto &[fy, fx] : formula[y][x])
            val[y][x] += eval(val, formula, fy, fx);
        formula[y][x].clear();
    }
    return val[y][x];
}

void solve() {
    int w, h;
    cin >> w >> h;

    vector<vector<int>> val(h, vector<int>(w));
    vector<vector<vector<pair<int, int>>>> formula(h, vector<vector<pair<int, int>>>(w));

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            string token;
            cin >> token;

            if (token[0] == '=')
                formula[y][x] = getFormula(token);
            else
                val[y][x] = stoi(token);
        }
    }

    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cout << eval(val, formula, y, x) << (x + 1 < w ? " " : "\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}