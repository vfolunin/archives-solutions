class Solution {
public:
    int numRabbits(vector<int> &a) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value]++;
        
        int res = 0;
        for (auto &[value, count] : count) {
            if (value + 1 >= count)
                res += value + 1;
            else
                res += (count + value) / (value + 1) * (value + 1);
        }
        return res;
    }
};