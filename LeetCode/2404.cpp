class Solution {
public:
    int mostFrequentEven(vector<int> &a) {
        map<int, int> count;
        for (int value : a)
            if (value % 2 == 0)
                count[value]++;
        
        int res = -1;
        for (auto &[value, _] : count)
            if (count[res] < count[value])
                res = value;
        return res;
    }
};