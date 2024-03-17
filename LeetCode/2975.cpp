class Solution {
    unordered_set<int> getGaps(int size, vector<int> &a) {
        a.push_back(1);
        a.push_back(size);
        sort(a.begin(), a.end());

        unordered_set<int> gaps;
        for (int l = 0; l < a.size(); l++)
            for (int r = l + 1; r < a.size(); r++)
                gaps.insert(a[r] - a[l]);
        return gaps;
    }

public:
    int maximizeSquareArea(int aSize, int bSize, vector<int> &a, vector<int> &b) {
        unordered_set<int> aGaps = getGaps(aSize, a);
        unordered_set<int> bGaps = getGaps(bSize, b);

        int maxGap = 0;
        for (int gap : aGaps) 
            if (bGaps.count(gap))
                maxGap = max(maxGap, gap);
        
        const long long MOD = 1e9 + 7;
        return maxGap ? 1LL * maxGap * maxGap % MOD : -1;
    }
};