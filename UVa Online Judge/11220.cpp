#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> readWords() {
    string line;
    if (!(getline(cin, line)) || line.empty())
        return {};

    vector<string> words;
    string word;

    for (char c : line) {
        if (c != ' ') {
            word += c;
        } else {
            words.push_back(word);
            word.clear();
        }
    }
    words.push_back(word);

    return words;
}

void solve(int test) {
    if (test > 1)
        cout << "\n";
    cout << "Case #" << test << ":\n";
    while (1) {
        vector<string> words = readWords();
        if (words.empty())
            break;
        for (int i = 0, j = 0; i < words.size(); i++)
            if (j < words[i].size())
                cout << words[i][j++];
        cout << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore(2);

    for (int test = 1; test <= n; test++)
        solve(test);
}