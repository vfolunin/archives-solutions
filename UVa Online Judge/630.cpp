#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int wordCount;
    cin >> wordCount;

    map<string, vector<string>> anagrams;
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;

        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());

        anagrams[sortedWord].push_back(word);
    }

    if (test)
        cout << "\n";
    while (1) {
        string word;
        cin >> word;

        if (word == "END")
            return;

        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());

        cout << "Anagrams for: " << word << "\n";
        if (!anagrams.count(sortedWord)) {
            cout << "No anagrams for: " << word << "\n";
        } else {
            int number = 1;
            for (auto &anagram : anagrams[sortedWord])
                cout << "  " << number++ << ") " << anagram << "\n";
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}