class Solution {
    long long getSum(long long l, long long r) {
        return (l + r) * (r - l + 1) / 2;
    }

public:
    long long maximumBooks(vector<int> &a) {
        vector<long long> res(a.size());
        vector<int> stack;

        for (int i = 0; i < a.size(); i++) {
            while (!stack.empty() && a[stack.back()] >= a[i] - (i - stack.back()))
                stack.pop_back();

            if (stack.empty())
                res[i] = getSum(a[i] - min(a[i], i), a[i]);
            else
                res[i] = res[stack.back()] + getSum(a[i] - (i - stack.back() - 1), a[i]);
            
            stack.push_back(i);
        }

        return *max_element(res.begin(), res.end());
    }
};