#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> readLetters() {
    string s;
    cin >> s;

    vector<int> count(26);
    for (char c : s)
        count[c - 'a']++;
    return count;
}

bool canMake(vector<int> &wordLetters, vector<int> &letters) {
    for (int i = 0; i < wordLetters.size(); i++)
        if (wordLetters[i] > letters[i])
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int wordCount;
    cin >> wordCount;

    vector<vector<int>> wordLetters(wordCount);
    for (vector<int> &wordLetters : wordLetters)
        wordLetters = readLetters();

    vector<int> letters = readLetters();

    int res = 0;
    for (vector<int> &wordLetters : wordLetters)
        res += canMake(wordLetters, letters);

    cout << res;
}