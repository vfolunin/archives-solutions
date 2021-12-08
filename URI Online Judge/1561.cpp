#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, m;
    char colon;
    if (!(cin >> h >> colon >> m))
        return 0;

    vector<string> clock = {
        " ____________________________________________",
        "|                                            |",
        "|    ____________________________________    |_",
        "|   |                                    |   |_)",
        "|   |   8         4         2         1  |   |",
        "|   |                                    |   |",
        "|   |   d         c         b         a  |   |",
        "|   |                                    |   |",
        "|   |                                    |   |",
        "|   |   f     e     d     c     b     a  |   |",
        "|   |                                    |   |",
        "|   |   32    16    8     4     2     1  |   |_",
        "|   |____________________________________|   |_)",
        "|                                            |",
        "|____________________________________________|"
    };

    for (int bit = 0; bit < 4; bit++)
        clock[6][clock[6].find('a' + bit)] = (h & (1 << bit) ? 'o' : ' ');
    for (int bit = 0; bit < 6; bit++)
        clock[9][clock[9].find('a' + bit)] = (m & (1 << bit) ? 'o' : ' ');

    for (string &row : clock)
        cout << row << "\n";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}