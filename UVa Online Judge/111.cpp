#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> readInts() {
    string line;
    if (!getline(cin, line))
        return {};
    stringstream ss(line);
    vector<int> res;
    int x;
    while (ss >> x)
        res.push_back(x);
    return res;
}

vector<int> rankingToOrdering(const vector<int> &ranking) {
    vector<int> ordering(ranking.size());
    for (int i = 0; i < ranking.size(); i++)
        ordering[ranking[i] - 1] = i;
    return ordering;
}

void solve(const vector<int> &a, const vector<int> &b) {
    vector<int> lcs(b.size(), 1);
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (find(a.begin(), a.end(), b[j]) - a.begin() <
                find(a.begin(), a.end(), b[i]) - a.begin())
                lcs[i] = max(lcs[i], lcs[j] + 1);
        }
    }
    cout << *max_element(lcs.begin(), lcs.end()) << "\n";
}

bool solve() {
    vector<int> a = rankingToOrdering(readInts());
    if (a.empty())
        return 0;
    while (1) {
        vector<int> b = rankingToOrdering(readInts());
        if (b.size() <= 1)
            break;
        solve(a, b);
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    while (solve());
}