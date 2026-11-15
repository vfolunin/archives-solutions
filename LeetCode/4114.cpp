class Solution {
public:
    long long countConsistent(vector<int> &a) {
        vector<int> l(a.size(), -1);
        vector<int> stack;
        for (int i = a.size() - 1; i >= 0; i--) {
            while (!stack.empty() && (a[stack.back()] == a[i] || (a[stack.back()] & a[i]) != a[stack.back()])) {
                l[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }
        
        vector<int> r(a.size(), a.size());
        stack.clear(); 
        for (int i = 0; i < a.size(); i++) {
            while (!stack.empty() && (a[stack.back()] & a[i]) != a[stack.back()]) {
                r[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }

        long long res = 0;
        for (int i = 0; i < a.size(); i++)
            res += 1LL * (i - l[i]) * (r[i] - i);
        return res;
    }
};