#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> split(string &s) {
    stringstream ss(s);
    vector<string> res;
    for (string s; ss >> s; )
        res.push_back(s);
    return res;
}

void solve() {
    string s;
    getline(cin, s);

    vector<string> words = split(s);
    reverse(words.begin(), words.end());

    for (int i = 0; i < words.size(); i++)
        cout << words[i] << (i + 1 < words.size() ? " " : "\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}