#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getTone(string &note) {
    static vector<string> notes1 = { "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#" };
    static vector<string> notes2 = { "A", "Bb", "Cb", "B#", "Db", "D", "Eb", "Fb", "E#", "Gb", "G", "Ab" };
    if (int i = find(notes1.begin(), notes1.end(), note) - notes1.begin(); i != 12)
        return i;
    return find(notes2.begin(), notes2.end(), note) - notes2.begin();
}

char getDelta(int toneA, int toneB) {
    if (toneA > toneB)
        toneB += 12;
    return toneB - toneA + 'a';
}

string canonize(vector<string> &notes) {
    vector<int> tones;
    for (string &note : notes)
        tones.push_back(getTone(note));

    string res;
    for (int i = 0; i + 1 < tones.size(); i++)
        res += getDelta(tones[i], tones[i + 1]);
    return res;
}

bool solve() {
    int textSize, patternSize;
    cin >> textSize >> patternSize;

    if (!textSize && !patternSize)
        return 0;

    vector<string> text(textSize);
    for (string &s : text)
        cin >> s;

    vector<string> pattern(patternSize);
    for (string &s : pattern)
        cin >> s;

    cout << (canonize(text).find(canonize(pattern)) != -1 ? "S\n" : "N\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}