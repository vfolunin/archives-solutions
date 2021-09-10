#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool fits(vector<string> &paragraphs, int w, int h, int fontSize) {
    int lineCount = 0;

    for (string &paragraph : paragraphs) {
        lineCount++;
        string line, word;

        for (char c : paragraph) {
            if (c != ' ') {
                word += c;
                continue;
            }

            if (word.size() * fontSize > w)
                return 0;

            if ((line.size() + !line.empty() + word.size()) * fontSize <= w) {
                line += (line.empty() ? "" : " ") + word;
            } else {
                lineCount++;
                line = word;
            }

            word.clear();
        }

        if (word.size() * fontSize > w)
            return 0;

        if ((line.size() + !line.empty() + word.size()) * fontSize <= w) {
            line += (line.empty() ? "" : " ") + word;
        } else {
            lineCount++;
            line = word;
        }
    }

    return lineCount * fontSize <= h;
}

void solve() {
    int paragraphCount;
    cin >> paragraphCount;
    cin.ignore();

    vector<string> paragraphs(paragraphCount);
    for (string &paragraph : paragraphs)
        getline(cin, paragraph);

    int w, h;
    cin >> w >> h;

    for (int fontSize = 28; fontSize >= 8; fontSize--) {
        if (fits(paragraphs, w, h, fontSize)) {
            cout << fontSize << "\n";
            return;
        }
    }

    cout << "No solution\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}