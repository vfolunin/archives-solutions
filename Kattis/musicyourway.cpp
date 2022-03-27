#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> readWords() {
    string line;
    getline(cin, line);

    vector<string> words;
    stringstream ss(line);
    string word;
    while (ss >> word)
        words.push_back(word);

    return words;
}

struct Comparator {
    int index;
    bool operator() (const vector<string> &a, const vector<string> &b) const {
        return a[index] < b[index];
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> attrs = readWords();

    int songCount;
    cin >> songCount;
    cin.ignore();

    vector<vector<string>> songs(songCount);
    for (vector<string> &song : songs)
        song = readWords();

    int comparisonCount;
    cin >> comparisonCount;

    for (int i = 0; i < comparisonCount; i++) {
        string attr;
        cin >> attr;

        Comparator comparator = { find(attrs.begin(), attrs.end(), attr) - attrs.begin() };
        stable_sort(songs.begin(), songs.end(), comparator);

        if (i)
            cout << "\n";
        for (int j = 0; j < attrs.size(); j++)
            cout << attrs[j] << (j + 1 < attrs.size() ? " " : "\n");
        for (vector<string> &song : songs)
            for (int j = 0; j < song.size(); j++)
                cout << song[j] << (j + 1 < song.size() ? " " : "\n");
    }
}