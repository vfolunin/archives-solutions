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

    int textCount, patternCount;
    cin >> textCount >> patternCount;

    vector<string> texts(textCount);
    for (string &text : texts)
        cin >> text;

    for (int patternIndex = 0; patternIndex < patternCount; patternIndex++) {
        string pattern;
        cin >> pattern;

        int bestText = -1, bestDiff = 1e9;
        for (int textIndex = 0; textIndex < textCount; textIndex++) {
            if (pattern.size() > texts[textIndex].size())
                continue;

            int minDiff = 1e9;
            for (int from = 0; from + pattern.size() <= texts[textIndex].size(); from++) {
                int diff = 0;
                for (int i = 0; i < pattern.size(); i++)
                    diff += texts[textIndex][from + i] != pattern[i];
                minDiff = min(minDiff, diff);
            }

            if (minDiff < bestDiff) {
                bestDiff = minDiff;
                bestText = textIndex;
            }
        }

        cout << bestText + 1 << "\n";
    }
}