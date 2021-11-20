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

bool solve(int test) {
    string s;
    if (!(cin >> s))
        return 0;

    cin.ignore();
    vector<string> tokens = readWords();
    int m = 0, f = 0;

    for (int i = 0; i < tokens.size(); i += 2) {
        if (tokens[i] == s) {
            m += tokens[i + 1] == "M";
            f += tokens[i + 1] == "F";
        }
    }

    if (test > 1)
        cout << "\n";
    cout << "Caso " << test << ":\n";
    cout << "Pares Iguais: " << m + f << "\n";
    cout << "F: " << f << "\n";
    cout << "M: " << m << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}