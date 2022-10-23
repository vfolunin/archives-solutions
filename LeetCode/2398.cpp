class Solution {
public:
    int maximumRobots(vector<int> &a, vector<int> &b, long long limit) {
        multiset<int> aSet;
        long long bSum = 0;
        int res = 0;
        
        for (int l = 0, r = -1; l < a.size(); l++) {
            while (r + 1 < a.size()) {
                ++r;
                aSet.insert(a[r]);
                bSum += b[r];
                
                if (*aSet.rbegin() + (r - l + 1) * bSum <= limit)
                    res = max(res, r - l + 1);
                else
                    break;
            }

            aSet.erase(aSet.find(a[l]));
            bSum -= b[l];
        }
        
        return res;
    }
};