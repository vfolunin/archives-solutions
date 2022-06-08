class Solution {
public:
    bool hasGroupsSizeX(vector<int> &a) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value]++;
        
        int res = count.begin()->second;
        for (auto &[value, count] : count)
            res = gcd(res, count);
        
        return res > 1;
    }
};