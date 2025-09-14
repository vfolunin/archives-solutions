class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int> &a, int targetSum) {
        sort(a.begin(), a.end());

        vector<int> can(targetSum + 1);
        can[0] = 1;
        vector<int> res(a.size());

        for (int limit = 1, i = 0; limit <= a.size(); limit++) {
            for (; i < a.size() && a[i] < limit; i++)
                for (int sum = targetSum; sum >= a[i]; sum--)
                    can[sum] |= can[sum - a[i]];
            
            for (int limitCount = 0; i + limitCount <= a.size() && limitCount * limit <= targetSum; limitCount++)
                res[limit - 1] |= can[targetSum - limitCount * limit];
        }

        return { res.begin(), res.end() };
    }
};