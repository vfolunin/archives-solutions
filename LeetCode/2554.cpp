class Solution {
public:
    int maxCount(vector<int> &a, int valueLimit, int sumLimit) {
        unordered_set<int> banned(a.begin(), a.end());

        int sum = 0, res = 0;
        for (int value = 1; value <= valueLimit; value++) {
            if (banned.count(value))
                continue;
            
            if (sum + value > sumLimit)
                break;

            sum += value;
            res++;
        }

        return res;
    }
};