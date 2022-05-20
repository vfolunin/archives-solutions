class Solution {
public:
    vector<int> twoOutOfThree(vector<int> &a, vector<int> &b, vector<int> &c) {
        unordered_map<int, set<char>> arrays;
        
        for (int value : a)
            arrays[value].insert('a');
        for (int value : b)
            arrays[value].insert('b');
        for (int value : c)
            arrays[value].insert('c');
        
        vector<int> res;
        for (auto &[value, arrays] : arrays)
            if (arrays.size() >= 2)
                res.push_back(value);
        
        return res;
    }
};