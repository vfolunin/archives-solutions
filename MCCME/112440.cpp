#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

struct Score {
    int score, time;

    bool operator < (const Score &that) const {
        if (score != that.score)
            return score > that.score;
        return time < that.time;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int recordCount;
    cin >> recordCount;

    unordered_map<string, Score> scores;
    for (int i = 0; i < recordCount; i++) {
        int score;
        string name;
        cin >> score >> name;
        if (!scores.count(name) || scores[name].score < score)
            scores[name] = { score, i };
    }

    vector<pair<string, Score>> pairs = { scores.begin(), scores.end() };
    sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });

    for (int i = 0; i < 3; i++)
        cout << i + 1 << " place. " << pairs[i].first << "(" << pairs[i].second.score << ")\n";
}