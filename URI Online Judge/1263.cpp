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
    vector<string> words = readWords();
    if (words.empty())
        return 0;

    int res = 0;
    for (int i = 0, j = 0; i < words.size(); i = j) {
        while (j < words.size() && tolower(words[i][0]) == tolower(words[j][0]))
            j++;
        res += j - i >= 2;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}