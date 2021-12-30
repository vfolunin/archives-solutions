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

    int questionCount, studentCount;
    string wrongAnswers;
    cin >> questionCount >> wrongAnswers >> studentCount;

    vector<vector<int>> answerCount(questionCount, vector<int>(26));
    for (int i = 0; i < studentCount; i++) {
        string answers;
        cin >> answers;
        for (int j = 0; j < questionCount; j++)
            if (answers[j] != wrongAnswers[j])
                answerCount[j][answers[j] - 'A']++;
    }

    int res = 0;
    for (int i = 0; i < questionCount; i++)
        res += *max_element(answerCount[i].begin(), answerCount[i].end());

    cout << res << "\n";
}