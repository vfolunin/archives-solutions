class Solution {
public:
    int firstUniqueEven(vector<int> &a) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value]++;
        
        for (int value : a)
            if (value % 2 == 0 && count[value] == 1)
                return value;
        return -1;
    }
};