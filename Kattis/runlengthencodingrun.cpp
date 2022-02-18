#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string encode(string s) {
    vector<pair<char, int>> pairs;
    for (char c : s) {
        if (pairs.empty() || pairs.back().first != c)
            pairs.push_back({ c, 1 });
        else
            pairs.back().second++;
    }
    string res;
    for (auto &[c, count] : pairs)
        res += c + to_string(count);
    return res;
}

string decode(string s) {
    stringstream ss(s);
    string res;
    char c;
    int count;
    while (ss >> c >> count)
        res += string(count, c);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string op, s;
    cin >> op >> s;

    cout << (op == "E" ? encode(s) : decode(s));
}