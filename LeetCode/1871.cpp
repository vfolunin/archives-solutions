class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<int> reachable = { 0 };
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0') {
                auto l = lower_bound(reachable.begin(), reachable.end(), i - maxJump);
                auto r = upper_bound(reachable.begin(), reachable.end(), i - minJump);
                if (l < r)
                    reachable.push_back(i);
            }
        }
        return reachable.back() == s.size() - 1;
    }
};