class Solution {
public:
    vector<int> onceTwice(vector<int> &a) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value]++;
        
        vector<int> res(2);
        for (auto &[value, count] : count)
            if (count < 3)
                res[count - 1] = value;
        return res;
    }
};