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
    int customerCount;
    cin >> customerCount;

    if (!customerCount)
        return 0;
    cin.ignore();

    map<string, set<string>> customers;
    for (int i = 0; i < customerCount; i++) {
        vector<string> words = readWords();
        for (int j = 1; j < words.size(); j++)
            customers[words[j]].insert(words[0]);
    }

    for (auto &[item, customers] : customers) {
        cout << item;
        for (const string &customer : customers)
            cout << " " << customer;
        cout << "\n";
    }
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}