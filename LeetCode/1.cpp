class Solution {
public:
    vector<int> twoSum(vector<int> &a, int sum) {
        unordered_map<int, int> pos;        
        for (int i = 0; i < a.size(); i++) {
            if (pos.count(sum - a[i]))
                return { i, pos[sum - a[i]] };
            pos[a[i]] = i;
        }
        return {};
    }
};