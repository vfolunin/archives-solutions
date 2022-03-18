#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void printSegments(vector<pair<int, int>> &segments) {
    for (int i = 0; i + 1 < segments.size(); i++) {
        cout << segments[i].first;
        if (segments[i].first != segments[i].second)
            cout << "-" << segments[i].second;
        cout << (i + 2 < segments.size() ? ", " : " and ");
    }

    cout << segments.back().first;
    if (segments.back().first != segments.back().second)
        cout << "-" << segments.back().second;
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int lineCount, errorCount;
    cin >> lineCount >> errorCount;

    set<int> errorLines;
    vector<pair<int, int>> error;

    for (int i = 0; i < errorCount; i++) {
        int x;
        cin >> x;
        errorLines.insert(x);
        if (!error.empty() && error.back().second + 1 == x)
            error.back().second++;
        else
            error.push_back({ x, x });
    }

    vector<pair<int, int>> correct;

    for (int x = 1; x <= lineCount; x++) {
        if (errorLines.count(x))
            continue;
        if (!correct.empty() && correct.back().second + 1 == x)
            correct.back().second++;
        else
            correct.push_back({ x, x });
    }

    cout << "Errors: ";
    printSegments(error);
    cout << "Correct: ";
    printSegments(correct);
}