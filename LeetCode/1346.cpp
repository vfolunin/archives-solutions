class Solution {
public:
    bool checkIfExist(vector<int> &a) {
        sort(a.begin(), a.end());
        int zeroCount = 0;
        
        for (int value : a) {
            if (value) {
                if (binary_search(a.begin(), a.end(), value * 2))
                    return 1;
            } else {
                zeroCount++;
            }
        }
        
        return zeroCount > 1;
    }
};