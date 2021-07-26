#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;


struct Solver {
    vector<string> words;
    vector<vector<int>> counts;
    vector<int> curCount, targetCount;
    vector<string> curAnagram;
    string targetAnagram;
    set<string> targetWords;

    vector<int> getCount(string &s) {
        vector<int> count(26);
        for (char c : s)
            if (c != ' ')
                count[c - 'A']++;
        return count;
    }

    int compareCount(vector<int> &a, vector<int> &b) {
        for (int i = 0; i < 26; i++)
            if (a[i] > b[i])
                return 1;
        for (int i = 0; i < 26; i++)
            if (a[i] < b[i])
                return -1;
        return 0;
    }

    void addCount(vector<int> &a, vector<int> &b) {
        for (int i = 0; i < 26; i++)
            a[i] += b[i];
    }

    void subCount(vector<int> &a, vector<int> &b) {
        for (int i = 0; i < 26; i++)
            a[i] -= b[i];
    }

    set<string> split(string &s) {
        set<string> words;
        string word;
        for (char c : s) {
            if (c != ' ') {
                word += c;
            } else if (!word.empty()) {
                words.insert(word);
                word.clear();
            }
        }
        if (!word.empty())
            words.insert(word);
        return words;
    }

    Solver() {
        while (1) {
            string word;
            cin >> word;

            if (word == "#")
                break;

            words.push_back(word);
        }

        sort(words.begin(), words.end());
        for (string &word : words)
            counts.push_back(getCount(word));
    }

    void rec(int i) {
        int cmp = compareCount(curCount, targetCount);
        if (cmp > 0)
            return;

        if (cmp == 0) {
            cout << targetAnagram << " =";
            for (string &word : curAnagram)
                cout << " " << word;
            cout << "\n";
            return;
        }

        if (i >= words.size())
            return;

        if (!targetWords.count(words[i])) {
            curAnagram.push_back(words[i]);
            addCount(curCount, counts[i]);
            rec(i + 1);
            curAnagram.pop_back();
            subCount(curCount, counts[i]);
        }

        rec(i + 1);
    }

    bool solve() {
        getline(cin, targetAnagram);
        if (targetAnagram == "#")
            return 0;

        curCount.assign(26, 0);
        targetCount = getCount(targetAnagram);
        targetWords = split(targetAnagram);
        rec(0);
        return 1;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Solver solver;
    cin.ignore();
    while (solver.solve());
}