class Solution {
    int findXSum(vector<int> &a, int from, int to, int limit) {
        unordered_map<int, int> count;
        for (int i = from; i <= to; i++)
            count[a[i]]++;
        
        vector<pair<int, int>> pairs(count.begin(), count.end());
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
            if (a.second != b.second)
                return a.second > b.second;
            return a.first > b.first;
        });

        int res = 0;
        for (int i = 0; i < pairs.size() && i < limit; i++)
            res += pairs[i].first * pairs[i].second;
        return res;
    }

public:
    vector<int> findXSum(vector<int> &a, int width, int limit) {
        vector<int> res;
        for (int from = 0, to = width - 1; to < a.size(); from++, to++)
            res.push_back(findXSum(a, from, to, limit));
        return res;
    }
};