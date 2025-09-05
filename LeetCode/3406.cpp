class Solution {
    void countSort(vector<int> &p, const vector<int> &rank) {
        vector<int> rankCount(p.size());
        for (int i = 0; i < p.size(); i++)
            rankCount[rank[i]]++;

        vector<int> rankFrom(p.size());
        for (int i = 1; i < p.size(); i++)
            rankFrom[i] = rankFrom[i - 1] + rankCount[i - 1];

        vector<int> sortedP(p.size());
        for (int elem : p)
            sortedP[rankFrom[rank[elem]]++] = elem;
        p.swap(sortedP);
    }

    vector<int> makeSuffixArray(string s) {
        s += '\0';

        vector<int> p(s.size());
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(), [&](int l, int r) {
            return s[l] < s[r];
        });

        vector<int> rank(s.size());
        rank[p[0]] = 0;
        for (int i = 1; i < s.size(); i++)
            rank[p[i]] = rank[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);

        vector<pair<int, int>> rankPair(s.size());
        for (int len = 1; len < s.size(); len *= 2) {
            for (int i = 0; i < s.size(); i++)
                rankPair[i] = { rank[i], rank[(i + len) % s.size()] };

            for (int i = 0; i < s.size(); i++)
                p[i] = (p[i] - len + s.size()) % s.size();
            countSort(p, rank);

            rank[p[0]] = 0;
            for (int i = 1; i < s.size(); i++)
                rank[p[i]] = rank[p[i - 1]] + (rankPair[p[i]] != rankPair[p[i - 1]]);
        }

        return p;
    }

public:
    string answerString(string &s, int partCount) {
        if (partCount == 1)
            return s;
            
        int from = makeSuffixArray(s).back();
        int partSize = s.size() - partCount + 1;
        return s.substr(from, partSize);
    }
};