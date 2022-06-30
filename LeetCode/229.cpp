class Solution {
public:
    vector<int> majorityElement(vector<int> &a) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value]++;
        
        vector<int> res;
        for (auto &[value, count] : count)
            if (count > a.size() / 3)
                res.push_back(value);
        return res;
    }
};