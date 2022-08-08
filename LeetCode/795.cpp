class Solution {
public:
    int numSubarrayBoundedMax(vector<int> &a, int minValue, int maxValue) {
        vector<int> l(a.size(), -1), stack;
        for (int i = a.size() - 1; i >= 0; i--) {
            while (!stack.empty() && a[stack.back()] <= a[i]) {
                l[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }
        
        vector<int> r(a.size(), a.size());
        stack.clear();
        for (int i = 0; i < a.size(); i++) {
            while (!stack.empty() && a[stack.back()] < a[i]) {
                r[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }

        int res = 0;
        for (int i = 0; i < a.size(); i++)
            if (minValue <= a[i] && a[i] <= maxValue)
                res += (i - l[i]) * (r[i] - i);
        return res;
    }
};