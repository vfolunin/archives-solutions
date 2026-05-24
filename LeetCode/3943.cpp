struct SqrtDecomposition {
    int blockSize, blockCount;
    vector<long long> a, blockAdd;
    vector<unordered_map<long long, int>> blockValueCount;

    SqrtDecomposition(vector<int> &a) : a(a.begin(), a.end()) {
        blockSize = sqrt(a.size());
        blockCount = (a.size() + blockSize - 1) / blockSize;

        blockAdd.resize(blockCount);
        blockValueCount.resize(blockCount);

        for (int i = 0; i < a.size(); i++)
            blockValueCount[i / blockSize][a[i]]++;
    }

    void add(int l, int r, int delta) {
        for (; l <= r && l % blockSize; l++) {
            blockValueCount[l / blockSize][a[l]]--;
            a[l] += delta;
            blockValueCount[l / blockSize][a[l]]++;
        }
        
        for (; l <= r && r % blockSize != blockSize - 1; r--) {
            blockValueCount[r / blockSize][a[r]]--;
            a[r] += delta;
            blockValueCount[r / blockSize][a[r]]++;
        }

        if (l <= r)
            for (int blockL = l / blockSize, blockR = r / blockSize; blockL <= blockR; blockL++)
                blockAdd[blockL] += delta;
    }

    int getCount(int value) {
        int res = 0;
        for (int blockI = 0; blockI < blockCount; blockI++)
            res += blockValueCount[blockI][value - blockAdd[blockI]];
        return res;
    }
};

class Solution {
public:
    vector<int> numberOfPairs(vector<int> &a, vector<int> &b, vector<vector<int>> &queries) {
        SqrtDecomposition sqrtDecomposition(b);
        vector<int> res;

        for (vector<int> &query : queries) {
            if (query[0] == 1) {
                sqrtDecomposition.add(query[1], query[2], query[3]);
            } else {
                res.push_back(0);
                for (int value : a)
                    res.back() += sqrtDecomposition.getCount(query[1] - value);
            }
        }

        return res;
    }
};