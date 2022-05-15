class Solution {
public:
    int findLucky(vector<int> &a) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value]++;
        
        int res = -1;
        for (auto &[value, count] : count)
            if (value == count)
                res = max(res, value);
        return res;
    }
};