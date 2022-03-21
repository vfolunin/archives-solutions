#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getSideCode(string &side) {
    static vector<string> sides = {
        "South", "East", "North", "West"
    };
    return find(sides.begin(), sides.end(), side) - sides.begin();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string fromSide, toSide, otherSide;
    cin >> fromSide >> toSide >> otherSide;

    int from = getSideCode(fromSide);
    int to = getSideCode(toSide);
    int other = getSideCode(otherSide);

    if ((from + 2) % 4 == to && (from + 1) % 4 == other ||
        (from + 3) % 4 == to && ((from + 1) % 4 == other || (from + 2) % 4 == other))
        cout << "Yes";
    else
        cout << "No";
}