#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SuffixArray {
    vector<int> p, lcp;

    void countSort(const vector<int> &rank) {
        int n = p.size();

        vector<int> rankCount(n);
        for (int i = 0; i < n; i++)
            rankCount[rank[i]]++;

        vector<int> rankFrom(n);
        for (int i = 1; i < n; i++)
            rankFrom[i] = rankFrom[i - 1] + rankCount[i - 1];

        vector<int> sortedP(n);
        for (int elem : p)
            sortedP[rankFrom[rank[elem]]++] = elem;
        p.swap(sortedP);
    }

    void makeP(string s) {
        s += '\0';
        int n = s.size();

        p.resize(n);
        for (int i = 0; i < n; i++)
            p[i] = i;
        sort(p.begin(), p.end(), [&](int i, int j) { return s[i] < s[j]; });

        vector<int> rank(n);
        rank[p[0]] = 0;
        for (int i = 1; i < n; i++)
            rank[p[i]] = rank[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);

        vector<pair<int, int>> rankPair(n);
        for (int len = 1; len < n; len *= 2) {
            for (int i = 0; i < n; i++)
                rankPair[i] = { rank[i], rank[(i + len) % n] };

            for (int i = 0; i < n; i++)
                p[i] = (p[i] - len + n) % n;
            countSort(rank);

            rank[p[0]] = 0;
            for (int i = 1; i < n; i++)
                rank[p[i]] = rank[p[i - 1]] + (rankPair[p[i]] != rankPair[p[i - 1]]);
        }
    }

    void makeLCP(const string &s) {
        int n = p.size();
        vector<int> positionInP(n);
        for (int i = 0; i < n; i++)
            positionInP[p[i]] = i;

        lcp.resize(n);
        for (int i = 0, len = 0; i < n - 1; i++, len = max(len - 1, 0)) {
            int j = p[positionInP[i] - 1];
            while (s[i + len] == s[j + len])
                len++;
            lcp[positionInP[i]] = len;
        }
    }

    SuffixArray(const string &s) {
        makeP(s);
        makeLCP(s);
    }
};

struct Counter {
    map<int, int> count;
    int uniqueCount = 0;

    void inc(int x) {
        uniqueCount += !count[x]++;
    }

    void dec(int x) {
        uniqueCount -= !--count[x];
    }
};

int getWordIndex(vector<int> &wordEnds, int i) {
    return upper_bound(wordEnds.begin(), wordEnds.end(), i) - wordEnds.begin();
}

bool solve(int test) {
    int wordCount;
    cin >> wordCount;

    if (!wordCount)
        return 0;

    string allWords;
    vector<int> wordEnds(wordCount);

    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;

        allWords += word + "#";
        wordEnds[i] = allWords.size() - 1;
    }

    SuffixArray sa(allWords);
    Counter counter;
    int half = wordCount / 2 + 1, maxLen = 0;
    vector<int> startPos;

    for (int l = wordCount + 1, r = wordCount + 1; l <= allWords.size(); l++) {
        while (r <= allWords.size() && counter.uniqueCount < half) {
            counter.inc(getWordIndex(wordEnds, sa.p[r]));
            r++;
        }

        if (counter.uniqueCount == half) {
            int len = wordEnds[getWordIndex(wordEnds, sa.p[l])] - sa.p[l];
            for (int i = l + 1; i < r; i++)
                len = min(len, sa.lcp[i]);

            if (maxLen < len) {
                maxLen = len;
                startPos.clear();
            }
            if (maxLen && maxLen == len)
                startPos.push_back(sa.p[l]);
        }

        counter.dec(getWordIndex(wordEnds, sa.p[l]));
    }

    if (test)
        cout << "\n";
    if (!maxLen) {
        cout << "?\n";
        return 1;
    }

    set<string> lcs;
    for (int pos : startPos)
        lcs.insert(allWords.substr(pos, maxLen));
    for (const string &s : lcs)
        cout << s << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}