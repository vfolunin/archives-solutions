#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string key;
    if (!getline(cin, key))
        return 0;

    static map<string, vector<string>> scales = {
        { "A",  { "A",  "B",  "C#", "D",  "E",  "F#", "G#" } },
        { "Bb", { "Bb", "C",  "D",  "Eb", "F",  "G",  "A"  } },
        { "B",  { "B",  "C#", "D#", "E",  "F#", "G#", "A#" } },
        { "C",  { "C",  "D",  "E",  "F",  "G",  "A",  "B"  } },
        { "Db", { "Db", "Eb", "F",  "Gb", "Ab", "Bb", "C"  } },
        { "D",  { "D",  "E",  "F#", "G",  "A",  "B",  "C#" } },
        { "Eb", { "Eb", "F",  "G",  "Ab", "Bb", "C",  "D"  } },
        { "E",  { "E",  "F#", "G#", "A",  "B",  "C#", "D#" } },
        { "F",  { "F",  "G",  "A",  "Bb", "C",  "D",  "E"  } },
        { "Gb", { "Gb", "Ab", "Bb", "Cb", "Db", "Eb", "F"  } },
        { "G",  { "G",  "A",  "B",  "C",  "D",  "E",  "F#" } },
        { "Ab", { "Ab", "Bb", "C",  "Db", "Eb", "F",  "G"  } }
    };
    vector<string> scale = scales[key];

    string line;
    getline(cin, line);
    replace(line.begin(), line.end(), ';', ' ');
    stringstream ss(line);

    cout << "Key of " << key << "\n";

    for (string note, dir, shift; ss >> note >> dir >> shift; ) {
        static vector<string> dirs = { "UP", "DOWN" };
        static vector<string> shifts = { "", "SECOND", "THIRD", "FOURTH", "FIFTH", "SIXTH", "SEVENTH", "OCTAVE" };

        int n = find(scale.begin(), scale.end(), note) - scale.begin();
        int d = dirs[0] == dir ? 1 : -1;
        int s = find(shifts.begin(), shifts.end(), shift) - shifts.begin();

        cout << note << ": ";
        if (n == 7)
            cout << "invalid note for this key\n";
        else
            cout << dir << " " << shift << " > " << scale[(n + (d * s) % 7 + 7) % 7] << "\n";
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}