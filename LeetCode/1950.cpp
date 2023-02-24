class Solution {
public:
    vector<int> findMaximums(vector<int> &a) {
        vector<int> l(a.size(), -1), stack;
        for (int i = a.size() - 1; i >= 0; i--) {
            while (!stack.empty() && a[stack.back()] > a[i]) {
                l[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }
        
        vector<int> r(a.size(), a.size());
        stack.clear();
        for (int i = 0; i < a.size(); i++) {
            while (!stack.empty() && a[stack.back()] > a[i]) {
                r[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }

        vector<int> res(a.size());
        for (int i = 0; i < a.size(); i++)
            res[r[i] - l[i] - 2] = max(res[r[i] - l[i] - 2], a[i]);
        for (int i = (int)a.size() - 2; i >= 0; i--)
            res[i] = max(res[i], res[i + 1]);
        return res;
    }
};