class Solution {
public:
    bool divideArray(vector<int> &a) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value]++;
        
        for (auto &[value, count] : count)
            if (count % 2)
                return 0;
        return 1;
    }
};