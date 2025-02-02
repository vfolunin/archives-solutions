class Solution {
public:
    int maxFreeTime(int size, int limit, vector<int> &l, vector<int> &r) {
        vector<int> gaps = { l[0] };
        for (int i = 0; i + 1 < l.size(); i++)
            gaps.push_back(l[i + 1] - r[i]);
        gaps.push_back(size - r.back());

        int sum = 0;
        for (int i = 0; i < limit + 1; i++)
            sum += gaps[i];
        
        int res = sum;
        for (int i = limit + 1; i < gaps.size(); i++) {
            sum += gaps[i] - gaps[i - limit - 1];
            res = max(res, sum);
        }
        return res;
    }
};