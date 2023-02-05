class Solution {
public:
    vector<int> separateDigits(vector<int> &a) {
        vector<int> res;
        for (int value : a)
            for (char c : to_string(value))
                res.push_back(c - '0');
        return res;
    }
};