#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const vector<string> notes = { "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#" };

int pos(string note) {
    note[0] = toupper(note[0]);
    if (note.size() == 2 && note[1] == 'b') {
        note[0] = (note[0] - 'A' + 6) % 7 + 'A';
        note[1] = '#';
    }
    return find(notes.begin(), notes.end(), note) - notes.begin();
}

map<set<int>, string> prepareChords() {
    map<set<int>, string> chords;
    for (int i = 0; i < 12; i++) {
        chords[set<int>{ i, (i + 4) % 12, (i + 7) % 12 }] = notes[i] + " Major";
        chords[set<int>{ i, (i + 3) % 12, (i + 7) % 12 }] = notes[i] + " Minor";
    }
    return chords;
}

bool solve() {
    string a, b, c;
    if (!(cin >> a >> b >> c))
        return 0;

    set<int> chord = { pos(a), pos(b), pos(c) };
    static map<set<int>, string> chords = prepareChords();

    cout << a << " " << b << " " << c << " is ";
    if (chords.count(chord))
        cout << "a " << chords[chord] << " chord.\n";
    else
        cout << "unrecognized.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}