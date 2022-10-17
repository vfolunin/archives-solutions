class Solution {
public:
    int validSubarraySize(vector<int> &a, int threshold) {
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
        
        for (int i = 0; i < a.size(); i++) {
            long long size = r[i] - l[i] - 1;
            if (a[i] * size > threshold)
                return size;
        }
        
        return -1;
    }
};