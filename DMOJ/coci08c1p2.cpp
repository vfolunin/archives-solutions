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

    int questionCount;
    string answers;
    cin >> questionCount >> answers;

    vector<int> score(3);
    for (int i = 0; i < questionCount; i++) {
        score[0] += i % 3 == answers[i] - 'A';
        score[1] += i % 4 == 1 && answers[i] == 'A' ||
            i % 2 == 0 && answers[i] == 'B' ||
            i % 4 == 3 && answers[i] == 'C';
        score[2] += 2 <= i % 6 && i % 6 <= 3 && answers[i] == 'A' ||
            4 <= i % 6 && i % 6 <= 5 && answers[i] == 'B' ||
            0 <= i % 6 && i % 6 <= 1 && answers[i] == 'C';
    }

    int maxScore = *max_element(score.begin(), score.end());
    vector<string> names = { "Adrian", "Bruno", "Goran" };

    cout << maxScore << "\n";
    for (int i = 0; i < score.size(); i++)
        if (score[i] == maxScore)
            cout << names[i] << "\n";
}