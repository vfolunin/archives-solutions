class Solution {
public:
    int maxBalancedShipments(vector<int> &a) {
        vector<int> stack, l(a.size(), -1);
        for (int i = a.size() - 1; i >= 0; i--) {
            while (!stack.empty() && a[stack.back()] < a[i]) {
                l[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }
        
        vector<int> res(a.size());
        for (int i = 1; i < res.size(); i++) {
            if (l[i] != -1)
                res[i] = (l[i] ? res[l[i] - 1] : 0) + 1;
            res[i] = max(res[i], res[i - 1]);
        }
        return res.back();
    }
};