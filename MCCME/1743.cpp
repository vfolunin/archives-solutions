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

    string cypher;
    int wordCount;
    cin >> cypher >> wordCount;

    sort(cypher.begin(), cypher.end());

    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;

        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());

        if (cypher == sortedWord)
            cout << word << "\n";
    }
}