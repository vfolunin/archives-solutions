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

    int yearCount;
    cin >> yearCount;
    cin.ignore();

    vector<int> score(4);

    for (int i = 0; i < yearCount; i++) {
        vector<string> guesses(5);
        for (string &guess : guesses)
            getline(cin, guess);

        vector<string> winners(5);
        for (string &winner : winners)
            getline(cin, winner);

        for (int j = 0; j < 4; j++)
            score[j] += guesses[j + 1] == winners[j + 1];
    }

    int minScore = *min_element(score.begin(), score.end());
    vector<int> res;

    for (int i = 0; i < 4; i++)
        if (score[i] == minScore)
            res.push_back(i + 1);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << (i + 1 < res.size() ? " " : "\n");
}