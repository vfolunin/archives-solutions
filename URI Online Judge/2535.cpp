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

bool solve() {
    int puppyCount;
    if (!(cin >> puppyCount))
        return 0;
    cin.ignore();

    int res = 0;

    for (int i = 0; i < puppyCount; i++) {
        vector<string> species = readWords();
        vector<string> breed = readWords();
        vector<string> name = readWords();
        cin.ignore();

        if (species != vector<string> { "cachorro" })
            continue;
        if (name.size() == 1)
            continue;

        bool goodName = 0;
        for (int i = 0; !goodName && i < name.size(); i++)
            goodName |= name[i][0] == breed[0][0];

        res += goodName;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}