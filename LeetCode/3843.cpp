class Solution {
public:
    int firstUniqueFreq(vector<int> &a) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value]++;
        
        unordered_map<int, int> count2;
        for (auto &[value, count] : count)
            count2[count]++;
        
        for (int value : a)
            if (count2[count[value]] == 1)
                return value;
        return -1;
    }
};