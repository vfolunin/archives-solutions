#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int wordCount, queryCount;
    cin >> wordCount >> queryCount;

    vector<string> words(wordCount);
    for (string &word : words)
        cin >> word;
    cin.ignore();

    for (int i = 0; i < queryCount; i++) {
        string text;
        getline(cin, text);

        bool found = 0;
        for (string &word : words) {
            if (text.find(word) != -1) {
                found = 1;
                break;
            }
        }

        cout << (found ? "DELETE\n" : "KEEP\n");
    }
}