class Solution {
public:
    int minOperations(vector<int> &a) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value]++;
        
        int res = 0;
        for (auto &[_, count] : count) {
            if (count == 1)
                return -1;            
            res += (count + 2) / 3;
        }        
        return res;
    }
};