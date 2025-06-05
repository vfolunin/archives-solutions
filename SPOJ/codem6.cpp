#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    stringstream ss(s);
    char c;
    int count;
    while (ss >> c >> count) {
        if (count % 2)
            cout << string(count, c);
        else
            cout << c << count;
    }
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}