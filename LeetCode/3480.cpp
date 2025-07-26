class Solution {
public:
    long long maxSubarrays(int size, vector<vector<int>> &pairs) {
        vector<vector<int>> rs(size + 1);

        for (vector<int> &pair : pairs) {
            int &l = pair[0], &r = pair[1];
            if (l > r)
                swap(l, r);

            rs[l].push_back(r);
        }

        long long res = 0;
        pair<int, int> minR = { size + 1, size + 1 };
        vector<long long> delta(size + 2);
        
        for (int l = size; l; l--) {
            for (int r : rs[l]) {
                if (minR.first > r)
                    minR = { r, minR.first };
                else if (minR.second > r)
                    minR.second = r;
            }

            res += minR.first - l;
            delta[minR.first] += minR.second - minR.first;
        }

        return res + *max_element(delta.begin(), delta.end());
    }
};