class Solution {
public:
    int longestAlternatingSubarray(vector<int> &a, int limit) {
        int res = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] <= limit && a[i] % 2 == 0) {
                int j = i + 1;
                while (j < a.size() && a[j] <= limit && a[j - 1] % 2 != a[j] % 2)
                    j++;
                
                res = max(res, j - i);
            }
        }
        
        return res;
    }
};