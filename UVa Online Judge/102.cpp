#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    vector<map<char, int>> bottles(3);
    int totalBottles = 0;
    for (int bin = 0; bin < 3; bin++) {
        for (char color : { 'B', 'G', 'C' }) {
            if (!(cin >> bottles[bin][color]))
                return 0;
            totalBottles += bottles[bin][color];
        }
    }

    string colors = "BCG", bestColors;
    int bestRes = -1;
    do {
        int res = 0;
        for (int bin = 0; bin < 3; bin++)
            res += bottles[bin][colors[bin]];
        if (res > bestRes) {
            bestRes = res;
            bestColors = colors;
        }
    } while (next_permutation(colors.begin(), colors.end()));

    cout << bestColors << " " << totalBottles - bestRes << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}