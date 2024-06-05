class Solution {
public:
    int minimumDifference(vector<int> &a, int target) {
        unordered_set<int> andSums;
        int res = 2e9;

        for (int value : a) {
            unordered_set<int> nextAndSums = { value };
            for (int andSum : andSums)
                nextAndSums.insert(andSum & value);
            andSums.swap(nextAndSums);

            for (int andSum : andSums)
                res = min(res, abs(andSum - target));
        }

        return res;
    }
};