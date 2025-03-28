class Solution {
public:
    vector<int> minBitwiseArray(vector<int> &a) {
        for (int &value : a) {
            bool found  = 0;
            for (int bit = 30; bit >= 0; bit--) {
                int resValue = value ^ (1 << bit);
                if ((resValue | (resValue + 1)) == value) {
                    value = resValue;
                    found = 1;
                    break;
                }
            }
            if (!found)
                value = -1;
        }
        return a;
    }
};