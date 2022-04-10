class Solution {
public:
    vector<int> twoSum(vector<int> &a, int sum) {
        for (int l = 0, r = a.size() - 1; l < r; l++) {
            while (l < r && a[l] + a[r] > sum)
                r--;
            
            if (a[l] + a[r] == sum)
                return { l + 1, r + 1 };
        }
        
        return {};
    }
};