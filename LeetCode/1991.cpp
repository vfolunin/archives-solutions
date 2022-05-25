class Solution {
public:
    int findMiddleIndex(vector<int> &a) {
        int sum = 0;
        for (int value : a)
            sum +=  value;
        
        for (int i = 0, halfSum = 0; i < a.size(); i++) {
            if (halfSum == sum - halfSum - a[i])
                return i;
            halfSum += a[i];
        }
        
        return -1;
    }
};