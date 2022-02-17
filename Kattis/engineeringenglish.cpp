#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    set<string> words;

    string line;
    while (getline(cin, line)) {
        stringstream ss(line);

        string word;
        while (ss >> word) {
            for (char &c : word)
                c = tolower(c);

            if (!words.count(word)) {
                cout << word << " ";
                words.insert(word);
            } else {
                cout << ". ";
            }
        }

        cout << "\n";
    }
}