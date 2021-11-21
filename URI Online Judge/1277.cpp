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

void solve() {
    int n;
    cin >> n;
    cin.ignore();

    vector<string> names = readWords();
    vector<string> marks = readWords();

    vector<string> denied;
    for (int i = 0; i < n; i++) {
        int a = count(marks[i].begin(), marks[i].end(), 'A');
        int m = count(marks[i].begin(), marks[i].end(), 'M');
        if (a * 4 > marks[i].size() - m)
            denied.push_back(names[i]);
    }

    for (int i = 0; i < denied.size(); i++)
        cout << denied[i] << (i + 1 < denied.size() ? " " : "");
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}