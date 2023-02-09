class Solution {
public:
    int validSubarrays(vector<int> &a) {
        vector<int> r(a.size(), a.size()), stack;
        for (int i = 0; i < a.size(); i++) {
            while (!stack.empty() && a[stack.back()] > a[i]) {
                r[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }

        int res = 0;
        for (int i = 0; i < r.size(); i++)
            res += r[i] - i;
        return res;
    }
};