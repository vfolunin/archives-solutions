#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int roundCount;
    cin >> roundCount;

    if (!roundCount)
        return 0;

    vector<int> score(3);
    for (int i = 0; i < roundCount; i++) {
        vector<int> num(3);
        for (int j = 0; j < 3; j++)
            cin >> num[j];

        int maxNum = *max_element(num.begin(), num.end());
        for (int j = 0; j < 3; j++)
            if (!(num[j] & (num[j] - 1)))
                score[j] += 1 + (num[j] == maxNum);
    }

    int winner = max_element(score.begin(), score.end()) - score.begin();
    if (count(score.begin(), score.end(), score[winner]) == 1) {
        static vector<string> name = { "Uilton", "Rita", "Ingred" };
        cout << name[winner] << "\n";
    } else {
        cout << "URI\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}