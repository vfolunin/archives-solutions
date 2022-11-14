#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int countryCount;
    cin >> countryCount;

    string line;
    getline(cin, line);

    unordered_map<string, string> countryOf;
    for (int i = 0; i < countryCount; i++) {
        getline(cin, line);
        vector<string> words = split(line);
        for (int i = 1; i < words.size(); i++)
            countryOf[words[i]] = words[0];
    }

    int cityCount;
    cin >> cityCount;

    for (int i = 0; i < cityCount; i++) {
        string city;
        cin >> city;
        cout << countryOf[city] << "\n";
    }
}