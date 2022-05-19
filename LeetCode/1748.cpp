class Solution {
public:
    int sumOfUnique(vector<int> &a) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value]++;
        
        int res = 0;
        for (auto &[value, count] : count)
            if (count == 1)
                res += value;
        return res;
    }
};