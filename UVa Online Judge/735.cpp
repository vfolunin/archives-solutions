#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int score;
    cin >> score;

    if (score <= 0)
        return 0;

    set<int> points = { 0, 50 };
    for (int i = 1; i <= 20; i++) {
        points.insert(i);
        points.insert(2 * i);
        points.insert(3 * i);
    }

    vector<int> dart(3);
    set<vector<int>> perm;
    set<multiset<int>> comb;

    for (auto i = points.begin(); i != points.end() && *i <= score; i++) {
        for (auto j = points.begin(); j != points.end() && *i + *j <= score; j++) {
            auto k = points.find(score - *i - *j);
            if (k != points.end()) {
                perm.insert({ *i, *j, *k });
                perm.insert({ *i, *k, *j });
                perm.insert({ *k, *i, *j });
                comb.insert({ *i, *j, *k });
            }
        }
    }

    if (comb.empty()) {
        cout << "THE SCORE OF " << score << " CANNOT BE MADE WITH THREE DARTS.\n";
    } else {
        cout << "NUMBER OF COMBINATIONS THAT SCORES " << score << " IS " << comb.size() << ".\n";
        cout << "NUMBER OF PERMUTATIONS THAT SCORES " << score << " IS " << perm.size() << ".\n";
    }
    cout << string(70, '*') << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
    cout << "END OF OUTPUT\n";
}