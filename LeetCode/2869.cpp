class Solution {
public:
    int minOperations(vector<int> &a, int k) {        
        vector<int> ops(k);
        for (int i = 0; i < a.size(); i++)
            if (a[i] <= k)
                ops[a[i] - 1] = a.size() - i;
        
        return *max_element(ops.begin(), ops.end());
    }
};