#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> countLetters(string &word) {
    vector<int> count(26);
    for (char c : word)
        if (islower(c))
            count[c - 'a']++;
    return count;
}

bool enoughLetters(vector<int> &have, vector<int> &need) {
    for (int i = 0; i < 26; i++)
        if (have[i] < need[i])
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> lettersNeed;
    while (1) {
        string word;
        cin >> word;

        if (word == "#")
            break;

        lettersNeed.push_back(countLetters(word));
    }

    cin.ignore();
    while (1) {
        string letters;
        getline(cin, letters);

        if (letters == "#")
            break;

        vector<int> have = countLetters(letters);

        int makeableWords = 0;
        for (vector<int> &need : lettersNeed)
            makeableWords += enoughLetters(have, need);

        cout << makeableWords << "\n";
    }
}