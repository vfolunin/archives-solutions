#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string line;
    if (!getline(cin, line))
        return 0;

    vector<pair<int, int>> stack = { { (int)1e9, 0 } };
    int x;

    stringstream ss(line);
    while (ss >> x) {
        if (x < 0) {
            stack.push_back({ -x, 0 });
        } else {
            if (stack.back().first != x) {
                cout << ":-( Try again.\n";
                return 1;
            }
            stack.pop_back();
            stack.back().second += x;
            if (stack.back().first <= stack.back().second) {
                cout << ":-( Try again.\n";
                return 1;
            }
        }
    }

    cout << (stack.size() == 1 ? ":-) Matrioshka!\n" : ":-( Try again.\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}