#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

vector<string> split(string &line) {
    vector<string> words;
    string word;
    for (char c : line) {
        if (c != ' ') {
            word += c;
        } else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty())
        words.push_back(word);
    return words;
}

void solve() {
    string voices;
    getline(cin, voices);

    unordered_set<string> knownVoices;
    while (1) {
        string voice;
        getline(cin, voice);

        if (voice.find("goes") == -1)
            break;

        knownVoices.insert(split(voice).back());
    }

    for (string voice : split(voices))
        if (!knownVoices.count(voice))
            cout << voice << " ";
    cout << "\n";
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