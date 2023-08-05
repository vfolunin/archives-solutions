class Solution {
public:
    int minimumSeconds(vector<int>& a) {
        unordered_map<int, int> last;
        for (int i = 0; i < a.size(); i++)
            last[a[i]] = i;
        
        unordered_map<int, int> gap;
        for (int i = 0; i < a.size(); i++) {
            int curGap = i - last[a[i]] - 1;
            if (curGap < 0)
                curGap += a.size();

            gap[a[i]] = max(gap[a[i]], curGap);
            last[a[i]] = i;
        }
        
        int res = 1e9;
        for (auto &[value, gap] : gap)
            res = min(res, (gap + 1) / 2);
        
        return res;
    }
};