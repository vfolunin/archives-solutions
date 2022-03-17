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

    int noteCount;
    cin >> noteCount;

    vector<pair<char, int>> notes;
    for (int i = 0; i < noteCount; i++) {
        char note;
        cin >> note;

        int count = 1;
        if (isdigit(cin.peek()))
            cin >> count;

        notes.push_back({ note, count });
    }

    string keys    = "GFEDCBAgfedcba";
    string symbols = " - - - - -   -";

    for (int i = 0; i < keys.size(); i++) {
        cout << keys[i] << ": ";
        for (int j = 0; j < noteCount; j++) {
            cout << string(notes[j].second, notes[j].first == keys[i] ? '*' : symbols[i]);
            cout << (j + 1 < noteCount ? symbols[i] : '\n');
        }
    }
}