#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> mode(3);
    for (string &s : mode)
        cin >> s;

    vector<vector<string>> modes = {
        { "black", "black", "green" },
        { "black", "black", "GREEN" },
        { "black", "yellow", "black" },
        { "red", "black", "black" },
        { "red", "yellow", "black" },
        { "black", "black", "green" },
        { "black", "YELLOW", "black" },
        { "black", "YELLOW", "black" }
    };

    int index = find(modes.begin(), modes.end(), mode) - modes.begin();
    if (index < modes.size()) {
        for (string &s : modes[index + 1])
            cout << s << "\n";
    } else {
        cout << "error";
    }
}