class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &a) {
        vector<int> stack, res(a.size(), -1);
        
        for (int i = 0; i < a.size(); i++) {
            while (!stack.empty() && a[stack.back()] < a[i]) {
                res[stack.back()] = a[i];
                stack.pop_back();
            }
            stack.push_back(i);
        }
        
        for (int i = 0; i < a.size(); i++) {
            while (!stack.empty() && a[stack.back()] < a[i]) {
                res[stack.back()] = a[i];
                stack.pop_back();
            }
        }
        
        return res;
    }
};