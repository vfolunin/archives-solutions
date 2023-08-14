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

    int size, wordCount;
    cin >> size >> wordCount;

    vector<int> count(26);

    for (int i = 0; i < size; i++) {
        string row;
        cin >> row;

        for (char c : row)
            count[c - 'A']++;
    }

    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;

        for (char c : word)
            count[c - 'A']--;
    }

    for (char c = 'A'; c <= 'Z'; c++)
        cout << string(count[c - 'A'], c);
}