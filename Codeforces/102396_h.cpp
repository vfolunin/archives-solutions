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

    int questionCount, participantCount;
    string answers;
    cin >> questionCount >> answers >> participantCount;

    vector<string> submissions(participantCount);
    for (string &submission : submissions)
        cin >> submission;

    vector<pair<int, int>> res;
    for (int a = 0; a < submissions.size(); a++) {
        for (int b = a + 1; b < submissions.size(); b++) {
            int aRight = 0, bRight = 0, commonRight = 0;
            int aWrong = 0, bWrong = 0, commonWrong = 0;
            for (int i = 0; i < answers.size(); i++) {
                if (submissions[a][i] == submissions[b][i]) {
                    if (submissions[a][i] == answers[i])
                        commonRight++;
                    else
                        commonWrong++;
                } else {
                    aRight += submissions[a][i] == answers[i];
                    bRight += submissions[b][i] == answers[i];
                    aWrong += submissions[a][i] != answers[i];
                    bWrong += submissions[b][i] != answers[i];
                }
            }

            if (commonRight > aRight && commonRight > bRight &&
                commonWrong > aWrong && commonWrong > bWrong)
                res.push_back({ a, b });
        }
    }

    cout << res.size() << "\n";
    for (auto &[a, b] : res)
        cout << a + 1 << " " << b + 1 << "\n";
}