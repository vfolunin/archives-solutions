#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(stringstream &ss) {
    string token;
    ss >> token;

    if (token == "+" || token == "-") {
        rec(ss);
        rec(ss);
    }
    cout << token << " ";
}

bool solve() {
    string s;
    getline(cin, s);

    if (s == "0")
        return 0;

    stringstream ss(s);
    rec(ss);
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}