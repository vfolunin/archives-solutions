#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(vector<string> &a, int y, int x, vector<string> &visited, string &word, set<string> &words) {
    if (word.size() == 4) {
        static string vowels = "AEIOUY";
        int vowelCount = 0;
        for (char c : word)
            vowelCount += vowels.find(c) != -1;
    
        if (vowelCount == 2)
            words.insert(word);
        return;
    }

    static int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    static int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

    for (int d = 0; d < 8; d++) {
        int ty = y + dy[d], tx = x + dx[d];
        if (0 <= ty && ty <= 3 && 0 <= tx && tx <= 3 && !visited[ty][tx]) {
            word.push_back(a[ty][tx]);
            visited[ty][tx] = 1;
            rec(a, ty, tx, visited, word, words);
            word.pop_back();
            visited[ty][tx] = 0;
        }
    }
}

set<string> getWords(vector<string> &a) {
    vector<string> visited(4, string(4, 0));
    string word;
    set<string> words;

    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
            rec(a, y, x, visited, word, words);

    return words;
}

bool solve(int test) {
    vector<string> a(4, string(4, 0)), b(4, string(4, 0));

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++)
            if (!(cin >> a[y][x]))
                return 0;
        for (int x = 0; x < 4; x++)
            cin >> b[y][x];
    }

    set<string> aWords = getWords(a);
    set<string> bWords = getWords(b);
    if (aWords.size() > bWords.size())
        swap(aWords, bWords);

    vector<string> res;
    for (const string &word : aWords)
        if (bWords.count(word))
            res.push_back(word);

    if (test)
        cout << "\n";
    if (res.empty()) {
        cout << "There are no common words for this pair of boggle boards.\n";
    } else {
        for (string &word : res)
            cout << word << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}