class Solution {
public:
    long long numberOfSubarrays(vector<int> &a) {
        vector<int> r(a.size(), a.size()), stack;
        for (int i = 0; i < a.size(); i++) {
            while (!stack.empty() && a[stack.back()] <= a[i]) {
                r[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }

        vector<int> rCount(a.size(), 1);
        long long res = 0;
        for (int i = a.size() - 1; i >= 0; i--) {
            if (r[i] < a.size() && a[i] == a[r[i]])
                rCount[i] += rCount[r[i]];
            res += rCount[i];
        }
        return res;
    }
};