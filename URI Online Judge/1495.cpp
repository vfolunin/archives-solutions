#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int matchCount, goals;
    if (!(cin >> matchCount >> goals))
        return 0;

    int res = 0;
    vector<int> loss;
    for (int i = 0; i < matchCount; i++) {
        int a, b;
        cin >> a >> b;

        if (a > b)
            res += 3;
        else
            loss.push_back(b - a);
    }

    sort(loss.begin(), loss.end());
    for (int needGoals : loss) {
        if (goals > needGoals) {
            goals -= needGoals + 1;
            res += 3;
        } else if (goals == needGoals) {
            goals -= needGoals;
            res++;
        } else {
            break;
        }
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}