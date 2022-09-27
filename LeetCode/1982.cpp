class Solution {
public:
    vector<int> recoverArray(int size, vector<int> &sums) {
        if (size == 1)
            return { sums[0] ? sums[0] : sums[1] };
        
        sort(sums.begin(), sums.end());
        int minValue = sums[sums.size() - 1] - sums[sums.size() - 2];
        
        unordered_map<int, int> count;
        for (int sum : sums)
            count[sum]++;
        
        vector<int> sums0, sums1;
        for (int sum : sums) {
            if (count[sum]) {
                sums0.push_back(sum);
                sums1.push_back(sum + minValue);
                count[sum]--;
                count[sum + minValue]--;
            }
        }
        
        if (find(sums0.begin(), sums0.end(), 0) != sums0.end()) {
            vector<int> res = recoverArray(size - 1, sums0);
            res.push_back(minValue);
            return res;
        } else {
            vector<int> res = recoverArray(size - 1, sums1);
            res.push_back(-minValue);
            return res;
        }
    }
};