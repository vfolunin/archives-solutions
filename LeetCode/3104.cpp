class Solution {
public:
    int maxSubstringLength(string &s) {
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.size(); i++)
            pos[s[i] - 'a'].push_back(i);
        
        int res = -1;
        for (int i = 0; i < pos.size(); i++) {
            if (pos[i].empty())
                continue;
            
            for (int l = pos[i].front(), r = pos[i].back(); r < s.size(); r = r + 1) {
                bool failed = 0;

                while (1) {
                    bool updated = 0;

                    for (int j = 0; j < pos.size(); j++) {
                        if (pos[j].empty())
                            continue;
                        
                        auto it = lower_bound(pos[j].begin(), pos[j].end(), l);
                        if (it != pos[j].end() && *it <= r) {
                            if (pos[j].front() < l) {
                                failed = 1;
                                break;
                            } else if (r < pos[j].back()) {
                                updated = 1;
                                r = pos[j].back();
                            }
                        }
                    }

                    if (failed || !updated)
                        break;
                }

                failed |= l == 0 && r == s.size() - 1;
                if (failed)
                    break;

                res = max(res, r - l + 1);
            }
        }

        return res;
    }
};