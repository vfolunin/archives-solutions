class Solution {
public:
    int missingMultiple(vector<int> &a, int factor) {
        sort(a.begin(), a.end());

        int value = factor;
        while (binary_search(a.begin(), a.end(), value))
            value += factor;
        
        return value;
    }
};