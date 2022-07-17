class Solution {
public:
    vector<int> numberOfPairs(vector<int> &a) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value]++;
        
        vector<int> res(2);
        for (auto &[value, count] : count) {
            res[0] += count / 2;
            res[1] += count % 2;
        }
        
        return res;
    }
};