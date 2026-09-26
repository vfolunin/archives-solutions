class Solution {
public:
    bool canTransform(vector<int> &a, vector<int> &b) {
        long long aSum = 0;
        for (int value : a)
            aSum += value;
        
        long long bSum = 0;
        for (int value : b)
            bSum += value;
        
        return aSum == bSum;
    }
};