class Solution {
public:
    int maxOperations(vector<int> &a, int targetSum) {
        sort(a.begin(), a.end());
        
        int res = 0;
        
        for (int l = 0, r = a.size() - 1; l < r; l++) {
            while (l < r && a[l] + a[r] > targetSum)
                r--;
            
            if (l < r && a[l] + a[r] == targetSum) {
                res++;
                r--;
            }
        }
        
        return res;
    }
};