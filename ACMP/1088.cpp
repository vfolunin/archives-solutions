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

    char x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    vector<pair<bool, string>> figures = {
        { x1 == x2 || y1 == y2, "Rook" },
        { abs(x1 - x2) == abs(y1 - y2), "Bishop" },
        { x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2), "Queen"},
        { abs(x1 - x2) * abs(y1 - y2) == 2, "Knight" },
        { abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1, "King" },
        { x1 == x2 && y1 != '1' && (y1 + 1 == y2 || y1 == '2' && y2 == '4'), "Pawn" }
    };

    bool found = 0;
    for (auto &[condition, name] : figures) {
        if (condition) {
            cout << name << "\n";
            found = 1;
        }
    }

    if (!found)
        printf("Nobody");
}