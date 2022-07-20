class Solution {
    int digitSum(int n) {
        int res = 0;
        while (n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
    
public:
    int maximumSum(vector<int> &a) {
        unordered_map<int, multiset<int>> groups;
        
        for (int value : a) {
            int sum = digitSum(value);
            groups[sum].insert(value);
            if (groups[sum].size() == 3)
                groups[sum].erase(groups[sum].begin());
        }
        
        int res = -1;
        
        for (auto &[sum, group] : groups)
            if (group.size() == 2)
                res = max(res, *group.begin() + *next(group.begin()));
        
        return res;
    }
};