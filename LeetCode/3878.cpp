class Solution {
public:
    long long countGoodSubarrays(vector<int> &a) {
        unordered_map<int, vector<int>> valuePos;
        for (int i = 0; i < a.size(); i++)
            valuePos[a[i]].push_back(i);
        for (auto &[value, pos] : valuePos)
            pos.push_back(a.size());

        vector<vector<int>> bitPos(30);
        for (int bit = 0; bit < bitPos.size(); bit++) {
            bitPos[bit].push_back(-1);
            for (int i = 0; i < a.size(); i++)
                if (a[i] & (1 << bit))
                    bitPos[bit].push_back(i);
            bitPos[bit].push_back(a.size());
        }
        
        long long res = 0;
        for (int i = 0; i < a.size(); i++) {
            int l = -1, r = *upper_bound(valuePos[a[i]].begin(), valuePos[a[i]].end(), i);
            for (int bit = 0; bit < 30; bit++) {
                if (!(a[i] & (1 << bit))) {
                    auto rIt = upper_bound(bitPos[bit].begin(), bitPos[bit].end(), i);
                    auto lIt = prev(rIt);
                    l = max(l, *lIt);
                    r = min(r, *rIt);
                }
            }
            res += 1LL * (i - l) * (r - i);
        }
        return res;
    }
};