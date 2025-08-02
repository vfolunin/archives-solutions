struct Counter {
    unordered_map<int, int> count;
    set<pair<int, int>> counts;

    void add(int value, int delta) {
        counts.erase({ count[value], -value });
        count[value] += delta;
        if (count[value])
            counts.insert({ count[value], -value });
        else
            count.erase(value);
    }
};

class Solution {
public:
    vector<int> subarrayMajority(vector<int> &a, vector<vector<int>> &queries) {
        for (int i = 0; i < queries.size(); i++)        
            queries[i].push_back(i);
        
        int blockSize = sqrt(a.size());
        sort(queries.begin(), queries.end(), [&](auto &lhs, auto &rhs) {
            int lBlock = lhs[0] / blockSize;
            int rBlock = rhs[0] / blockSize;
            if (lBlock != rBlock)
                return lBlock < rBlock;
            return lhs[1] < rhs[1];
        });

        Counter counter;
        counter.add(a[0], 1);
        int l = 0, r = 0;
        vector<int> res(queries.size());

        for (vector<int> &query : queries) {
            while (l < query[0])
                counter.add(a[l++], -1);
            while (query[1] < r)
                counter.add(a[r--], -1);
            while (query[0] < l)
                counter.add(a[--l], 1);
            while (r < query[1])
                counter.add(a[++r], 1);

            auto [count, value] = *counter.counts.rbegin();
            res[query[3]] = count >= query[2] ? -value : -1;
        }

        return res;
    }
};