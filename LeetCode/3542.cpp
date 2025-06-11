class Solution {
public:
    int minOperations(vector<int> &a) {
        vector<int> r(a.size(), a.size()), stack;
        map<int, vector<int>> pos;

        for (int i = 0; i < a.size(); i++) {
            while (!stack.empty() && a[stack.back()] > a[i]) {
                r[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
            pos[a[i]].push_back(i);
        }

        int res = 0;
        
        for (auto &[value, pos] : pos) {
            if (!value)
                continue;
            
            for (int i = 0, to = -1; i < pos.size(); i++) {
                if (to <= pos[i]) {
                    res++;
                    to = r[pos[i]];
                }
            }
        }

        return res;
    }
};