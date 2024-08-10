#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string removeCommas(string &s) {
    s.erase(remove(s.begin(), s.end(), ','), s.end());
    return s;
}

bool solve() {
    string sa, sb;
    if (!(cin >> sa >> sb))
        return 0;

    cout << stoi(removeCommas(sa)) + stoi(removeCommas(sb)) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}