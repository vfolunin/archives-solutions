#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string line;
    getline(cin, line);

    string letters;
    for (char c : line)
        if (isupper(c))
            letters += c;

    if (letters.empty()) {
        cout << "0 0\n";
        return;
    }

    sort(letters.begin(), letters.end());
    letters.erase(unique(letters.begin(), letters.end()), letters.end());

    vector<int> maxLen(letters.size(), 1);
    vector<int> maxCount(letters.size(), 1);
    
    for (int i = 1; i < letters.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (5 * (letters[j] - 'A' + 1) <= 4 * (letters[i] - 'A' + 1)) {
                if (maxLen[i] < maxLen[j] + 1) {
                    maxLen[i] = maxLen[j] + 1;
                    maxCount[i] = maxCount[j];
                } else if (maxLen[i] == maxLen[j] + 1) {
                    maxCount[i] += maxCount[j];
                }
            }
        }
    }

    int resLen = *max_element(maxLen.begin(), maxLen.end());
    int resCount = 0;
    for (int i = 0; i < letters.size(); i++)
        if (maxLen[i] == resLen)
            resCount += maxCount[i];

    cout << resLen << " " << resCount << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}