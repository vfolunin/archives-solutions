#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Problem {
    int a, b;

    bool operator < (const Problem &that) const {
        if (a < b) {
            if (that.a < that.b)
                return a < that.a;
            else
                return 1;
        } else {
            if (that.a < that.b)
                return 0;
            else
                return b > that.b;
        }
    }
};

bool solve() {
    int problemCount;
    if (!(cin >> problemCount))
        return 0;

    vector<Problem> problems(problemCount);
    for (auto &[a, b] : problems)
        cin >> a;
    for (auto &[a, b] : problems)
        cin >> b;

    sort(problems.begin(), problems.end());

    int freeA = 0, freeB = 0;
    for (auto &[a, b] : problems) {
        freeA += a;
        freeB = max(freeA, freeB) + b;
    }

    cout << freeB << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}