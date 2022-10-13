class Solution {
public:
    int minDeletionSize(vector<string> &a) {
        vector<int> colCount(a[0].size(), 1);
        
        for (int i = 1; i < a[0].size(); i++) {
            for (int j = 0; j < i; j++) {
                bool ok = 1;
                for (string &s : a)
                    ok &= s[j] <= s[i];
                
                if (ok)
                    colCount[i] = max(colCount[i], colCount[j] + 1);
            }
        }
        
        return a[0].size() - *max_element(colCount.begin(), colCount.end());
    }
};