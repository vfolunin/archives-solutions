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
    int lineCount;
    cin >> lineCount;
    cin.ignore();

    vector<pair<string, string>> people;

    for (int i = 0; i < lineCount; i++) {
        string line;
        getline(cin, line);
        
        vector<string> parts = split(line, ' ');

        string name = parts[0];
        name.pop_back();

        string rank;
        static const vector<string> ranks = { "upper", "middle", "lower" };
        for (const string &part : split(parts[1], '-'))
            rank += find(ranks.begin(), ranks.end(), part) - ranks.begin() + '0';
        reverse(rank.begin(), rank.end());
        rank += string(20 - rank.size(), '1');

        people.push_back({ rank, name });
    }

    sort(people.begin(), people.end());

    for (auto &[rank, name] : people)
        cout << name << "\n";
    cout << string(30, '=') << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}