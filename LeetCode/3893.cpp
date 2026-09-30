class Solution {
public:
    int maximumTeamSize(vector<int> &l, vector<int> &r) {
        vector<int> ls = l;
        sort(ls.begin(), ls.end());

        vector<int> rs = r;
        sort(rs.begin(), rs.end());
        
        int res = 1;
        for (int i = 0; i < l.size(); i++) {
            int cur = upper_bound(ls.begin(), ls.end(), r[i]) - ls.begin();
            cur -= lower_bound(rs.begin(), rs.end(), l[i]) - rs.begin();
            res = max(res, cur);
        }
        return res;
    }
};