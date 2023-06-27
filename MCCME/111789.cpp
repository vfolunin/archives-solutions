#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

void countSort(vector<int> &p, const vector<int> &rank) {
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

vector<int> makeSuffixArray(string s) {
    s += '\0';
    int n = s.size();

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
        return s[i] < s[j];
    });

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
        countSort(p, rank);

        rank[p[0]] = 0;
        for (int i = 1; i < n; i++)
            rank[p[i]] = rank[p[i - 1]] + (rankPair[p[i]] != rankPair[p[i - 1]]);
    }

    return p;
}

vector<int> makeLCP(const string &s, const vector<int> &p) {
    int n = p.size();
    vector<int> positionInP(n);
    for (int i = 0; i < n; i++)
        positionInP[p[i]] = i;

    vector<int> lcp(n);
    for (int i = 0, len = 0; i < n - 1; i++, len = max(len - 1, 0)) {
        int j = p[positionInP[i] - 1];
        while (s[i + len] == s[j + len])
            len++;
        lcp[positionInP[i]] = len;
    }
    return lcp;
}

long long distinctSubstringCount(const vector<int> &p, const vector<int> &lcp) {
    long long res = 0;
    for (int i = 1; i < p.size(); i++)
        res += (p.size() - 1 - p[i]) - lcp[i];
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    vector<int> p = makeSuffixArray(s);
    vector<int> lcp = makeLCP(s, p);
    cout << distinctSubstringCount(p, lcp);
}