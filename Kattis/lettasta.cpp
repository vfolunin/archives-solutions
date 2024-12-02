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

    int problemCount, teamCount;
    cin >> problemCount >> teamCount;

    vector<string> problemName(problemCount);
    for (string &name : problemName)
        cin >> name;

    vector<int> scoreSum(problemCount);
    for (int i = 0; i < teamCount; i++) {
        for (int j = 0; j < problemCount; j++) {
            int score;
            cin >> score;

            scoreSum[j] += score;
        }
    }

    cout << problemName[max_element(scoreSum.begin(), scoreSum.end()) - scoreSum.begin()];
}