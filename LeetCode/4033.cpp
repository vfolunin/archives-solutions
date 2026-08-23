struct Query {
    int l, r, block, index;

    bool operator < (const Query &that) const {
        if (block != that.block)
            return block < that.block;
        return r < that.r;
    }
};

struct Counter {
    unordered_map<int, int> count;
    int odd = 0;

    void add(int value, int delta) {
        odd -= count[value] % 2;
        count[value] += delta;
        odd += count[value] % 2;
        if (!count[value])
            count.erase(value);
    }

    bool isOk(int targetSize) {
        return count.size() == targetSize && !odd;
    }
};

class Solution {
public:
    vector<bool> validSubarrays(vector<int> &a, int targetCount, vector<vector<int>> &queryArgs) {
        int blockSize = sqrt(a.size());

        vector<Query> queries;
        for (int i = 0; i < queryArgs.size(); i++)
            queries.push_back({ queryArgs[i][0], queryArgs[i][1], queryArgs[i][0] / blockSize, i });
        sort(queries.begin(), queries.end());

        Counter counter;
        int l = 0, r = 0;
        counter.add(a[0], 1);

        vector<bool> res(queryArgs.size());
        for (auto &[queryL, queryR, block, index] : queries) {
            while (queryL < l)
                counter.add(a[--l], 1);
            while (l < queryL)
                counter.add(a[l++], -1);
            while (queryR < r)
                counter.add(a[r--], -1);
            while (r < queryR)
                counter.add(a[++r], 1);
            
            res[index] = counter.isOk(targetCount);
        }
        return res;
    }
};