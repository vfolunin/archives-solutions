#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Counter {
    vector<int> count;
    int uniqueCount = 0;

    Counter(int k) : count(k) {}

    void inc(int x) {
        uniqueCount += !count[x]++;
    }

    void dec(int x) {
        uniqueCount -= !--count[x];
    }
};

void solve(int test) {
    map<string, int> wordId;
    vector<int> words;
    string word;

    while (1) {
        char c = cin.get();
        if (isalpha(c)) {
            word += c;
        } else if (!word.empty()) {
            if (word == "END")
                break;
            if (!wordId.count(word))
                wordId[word] = wordId.size();
            words.push_back(wordId[word]);
            word = "";
        }
    }

    Counter counter(wordId.size());
    int bestL = 0, bestR = words.size() - 1;

    for (int l = 0, r = 0; l < words.size(); l++) {
        while (r < words.size() && counter.uniqueCount < wordId.size())
            counter.inc(words[r++]);
        if (counter.uniqueCount == wordId.size() && bestR + 1 - bestL > r - l) {
            bestL = l;
            bestR = r - 1;
        }
        counter.dec(words[l]);
    }

    cout << "Document " << test << ": " << bestL + 1 << " " << bestR + 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}