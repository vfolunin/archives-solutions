#include <iostream>
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

    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ' ' && i + 1 < line.size() &&
            (line[i + 1] == '.' || line[i + 1] == ','))
            continue;
        cout << line[i];
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}