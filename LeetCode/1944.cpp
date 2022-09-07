class Solution {
public:
    vector<int> canSeePersonsCount(vector<int> &a) {
        vector<int> res(a.size()), stack;
        
        for (int i = a.size() - 1; i >= 0; i--) {
            while (!stack.empty() && stack.back() <= a[i]) {
                res[i]++;
                stack.pop_back();
            }
            res[i] += !stack.empty();
            stack.push_back(a[i]);
        }
        
        return res;
    }
};