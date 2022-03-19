#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> split(string &line, char delimiter) {
    vector<string> words;
    string word;

    for (char c : line) {
        if (c != delimiter) {
            word += c;
        } else {
            words.push_back(word);
            word.clear();
        }
    }
    words.push_back(word);

    return words;
}

void solve() {
    string line;
    getline(cin, line);

    long long value = 0;
    for (string &part : split(line, ','))
        value = value * 60 + (part.empty() ? 0 : stoi(part));

    cout << value << "\n";
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