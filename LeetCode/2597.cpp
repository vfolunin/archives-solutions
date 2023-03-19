class Solution {    
    void rec(vector<int> &a, int i, int diff, vector<int> &taken, int &res) {
        if (i == a.size()) {
            res += !taken.empty();
            return;
        }
        
        rec(a, i + 1, diff, taken, res);
        
        if (!binary_search(taken.begin(), taken.end(), a[i] - diff)) {
            taken.push_back(a[i]);
            rec(a, i + 1, diff, taken, res);
            taken.pop_back();
        }
    }
    
public:
    int beautifulSubsets(vector<int> &a, int diff) {
        sort(a.begin(), a.end());

        vector<int> taken;
        int res = 0;
        rec(a, 0, diff, taken, res);
        
        return res;
    }
};