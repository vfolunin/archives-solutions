#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

char complement(char c) {
    static string nucleotides = "BSCF";
    return nucleotides[nucleotides.find(c) ^ 1];
}

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    string stack;
    int connectionCount = 0;

    for (char c : s) {
        if (stack.empty() || stack.back() != complement(c)) {
            stack.push_back(c);
        } else {
            stack.pop_back();
            connectionCount++;
        }
    }

    cout << connectionCount << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}