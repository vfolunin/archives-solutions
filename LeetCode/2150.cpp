class Solution {
public:
    vector<int> findLonely(vector<int> &a) {
        unordered_map<int, int> frequency;
        for (int value : a)
            frequency[value]++;
        
        vector<int> res;
        for (auto &[value, count] : frequency)
            if (count == 1 && !frequency.count(value - 1) && !frequency.count(value + 1))
                res.push_back(value);
        return res;
    }
};