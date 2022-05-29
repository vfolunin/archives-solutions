class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &a) {
        vector<int> res(a.size()), stack;
        for (int i = 0; i < a.size(); i++) {
            while (!stack.empty() && a[stack.back()] < a[i]) {
                res[stack.back()] = i - stack.back();
                stack.pop_back();
            }
            stack.push_back(i);
        }
        return res;
    }
};