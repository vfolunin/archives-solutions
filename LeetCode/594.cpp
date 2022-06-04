class Solution {
public:
    int findLHS(vector<int> &a) {
        map<int, int> count;
        for (int value : a)
            count[value]++;
        
        int res = 0;
        for (auto l = count.begin(), r = next(count.begin()); r != count.end(); l++, r++)
            if (l->first + 1 == r->first)
                res = max(res, l->second + r->second);
        return res;
    }
};