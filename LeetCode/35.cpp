class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int l = -1, r = nums.size();
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < target)
                l = m;
            else
                r = m;
        }
        return r;
    }
};