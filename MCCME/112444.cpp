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

    int size;
    cin >> size;

    vector<pair<string, int>> participants(size);
    int maxScore = 0;

    for (auto &[name, score] : participants) {
        string surname, firstName;
        int a, b, c;
        cin >> surname >> firstName >> a >> b >> c;

        name = surname + " " + firstName;
        score = a + b + c;
        maxScore = max(maxScore, score);
    }

    for (auto &[name, score] : participants)
        if (score == maxScore)
            cout << name << "\n";
}