class Solution {
public:
    long long bowlSubarrays(vector<int> &a) {
        vector<int> l(a.size(), -1), stack;
        for (int i = a.size() - 1; i >= 0; i--) {
            while (!stack.empty() && a[stack.back()] <= a[i]) {
                l[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }

        vector<int> r(a.size(), -1);
        stack.clear();
        for (int i = 0; i < a.size(); i++) {
            while (!stack.empty() && a[stack.back()] <= a[i]) {
                r[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }

        long long res = 0;
        for (int i = 0; i < r.size(); i++)
            res += l[i] != -1 && r[i] != -1;
        return res;
    }
};