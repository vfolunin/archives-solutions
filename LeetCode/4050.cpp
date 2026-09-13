class Solution {
public:
    int minDays(int target) {
        vector<int> res(target + 1, 1e9);
        res[0] = 0;
        for (int count = 1; count <= target; count++)
            for (int sum = 0, add = 1; sum <= count; sum += add, add++)
                res[count] = min(res[count], res[count - sum] + add);
        return res.back() - 1;
    }
};