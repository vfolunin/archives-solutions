#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int candidateCount;
    cin >> candidateCount;
    cin.ignore();

    vector<string> candidateNames(candidateCount);
    for (string &name : candidateNames)
        getline(cin, name);

    vector<vector<int>> votes;
    while (1) {
        string line;
        getline(cin, line);
        if (line.empty())
            break;
        stringstream ss(line);
        votes.push_back(vector<int>(candidateCount));
        for (int &vote : votes.back()) {
            ss >> vote;
            vote--;
        }
    }

    vector<bool> isEliminated(candidateCount);
    while (1) {
        vector<int> score(candidateCount);

        for (vector<int> &vote : votes) {
            int i = 0;
            while (isEliminated[vote[i]])
                i++;
            score[vote[i]]++;
        }

        int minScore = 1e9, maxScore = -1;
        for (int i = 0; i < candidateCount; i++) {
            if (!isEliminated[i]) {
                minScore = min(minScore, score[i]);
                maxScore = max(maxScore, score[i]);
            }
        }

        if (maxScore * 2 > votes.size() || minScore == maxScore) {
            if (test)
                cout << "\n";
            for (int i = 0; i < candidateCount; i++)
                if (score[i] == maxScore)
                    cout << candidateNames[i] << "\n";
            break;
        }

        for (int i = 0; i < candidateCount; i++)
            if (score[i] == minScore)
                isEliminated[i] = 1;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}