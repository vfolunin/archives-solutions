class Solution {
public:
    int sumDivisibleByK(vector<int> &a, int d) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value]++;
        
        int res = 0;
        for (auto &[value, count] : count)
            if (count % d == 0)
                res += value * count;
        return res;
    }
};