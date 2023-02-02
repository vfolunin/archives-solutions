class Solution {
public:
    int countElements(vector<int> &a) {
        unordered_map<int, int> valueCount;
        for (int value : a)
            valueCount[value]++;
        
        int res = 0;
        for (auto [value, count] : valueCount)
            if (valueCount.count(value + 1))
                res += count;
        return res;
    }
};