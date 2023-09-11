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

    int lineCount;
    cin >> lineCount;
    cin.ignore();

    vector<string> lines(lineCount);
    int bCount = 0, gCount = 0;

    for (int i = 0; i < lines.size(); i++) {
        getline(cin, lines[i]);
        for (char c : lines[i]) {
            bCount += tolower(c) == 'b';
            gCount += tolower(c) == 'g';
        }

        cout << lines[i];
        if (i + 1 < lines.size())
            cout << "\n";
        else if (bCount < gCount)
            cout << " is GOOD";
        else if (bCount > gCount)
            cout << " is A BADDY";
        else
            cout << " is NEUTRAL";
    }
}