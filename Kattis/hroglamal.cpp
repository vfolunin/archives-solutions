#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int translationCount;
    cin >> translationCount;

    unordered_map<string, string> translation;
    for (int i = 0; i < translationCount; i++) {
        string word;
        cin >> word >> translation[word];
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        string word;
        cin >> word;

        if (count_if(word.begin(), word.end(), [](char c) {
            return !isalpha(c);
        }))
            cout << word << "\n";
        else if (translation.contains(word))
            cout << translation[word] << "\n";
        else
            cout << "?" << word << "?\n";
    }
}