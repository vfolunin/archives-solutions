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

    int tuneNoteCount;
    cin >> tuneNoteCount;

    vector<string> tune(tuneNoteCount);
    for (string &tuneNote : tune)
        cin >> tuneNote;

    static vector<string> notes = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
    set<string> res;

    for (int i = 0; i < notes.size(); i++) {
        set<string> scale;
        for (int d : {0, 2, 4, 5, 7, 9, 11})
            scale.insert(notes[(i + d) % notes.size()]);

        bool ok = 1;
        for (string &note : tune)
            ok &= scale.count(note);

        if (ok)
            res.insert(notes[i]);
    }

    if (res.empty()) {
        cout << "none";
    } else {
        for (const string &note : res)
            cout << note << " ";
    }
}