#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string time;
    cin >> time;

    if (time == "end") {
        cout << "end\n";
        return 0;
    }

    static vector<string> digits = {
        "+---+      +  +---+  +---+  +   +  +---+  +---+  +---+  +---+  +---+     ",
        "|   |      |      |      |  |   |  |      |          |  |   |  |   |     ",
        "|   |      |      |      |  |   |  |      |          |  |   |  |   |  o  ",
        "+   +      +  +---+  +---+  +---+  +---+  +---+      +  +---+  +---+     ",
        "|   |      |  |          |      |      |  |   |      |  |   |      |  o  ",
        "|   |      |  |          |      |      |  |   |      |  |   |      |     ",
        "+---+      +  +---+  +---+      +  +---+  +---+      +  +---+  +---+     ",
    };

    for (int row = 0; row < digits.size(); row++) {
        for (int i = 0; i < time.size(); i++) {
            if (time[i] == ':')
                cout << digits[row].substr(70);
            else
                cout << digits[row].substr((time[i] - '0') * 7, i + 1 < time.size() ? 7 : 5);
        }
        cout << "\n";
    }

    cout << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}